package kr.icia.controller;

import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.List;

import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.security.access.prepost.PreAuthorize;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.servlet.mvc.support.RedirectAttributes;

import kr.icia.domain.BoardAttachVO;
import kr.icia.domain.BoardVO;
import kr.icia.domain.Criteria;
import kr.icia.domain.PageDTO;
import kr.icia.service.BoardService;
import lombok.AllArgsConstructor;
import lombok.extern.log4j.Log4j;

@Log4j
@Controller
@RequestMapping("/board/*")
@AllArgsConstructor
public class BoardController {
	private BoardService service;

	// list(model,cri);
	// 자바에서는 전달값을 주면서 호출해야 했지만,
	// 스프링의 컨트롤러 에서는
	// 매개변수에 사용하겠다고 명시하면, 알아서 만들어 줌.
	@GetMapping("/list")
	public void list(Model model, Criteria cri) {
		// Criteria cri 는 기본 생성자로 1,10을 가지고 있음.
		log.info("list");
		model.addAttribute("list", service.getList(cri));
		// java 코드에서 생성된 결과를 jsp 페이지로 전달.

		// 컨트롤러 >> 서비스 >> 매퍼 >> mybatis
//		model.addAttribute("pageMaker", new PageDTO(cri, 190));
		// 총 게시물 수를 임의로 190 설정.
		int total = service.getTotal(cri);
		log.info("total : " + total);
		model.addAttribute("pageMaker", new PageDTO(cri, total));

	}

	// 글쓰기 버튼을 누르면, 게시물 입력폼 보이기.
	@GetMapping("/register")
	@PreAuthorize("isAuthenticated()") // 로그인한 사용자만 접근.
	public void register() {
		// 이동할 주소를 리턴하지 않는다면, 요청한 이름으로의 jsp 파일을 찾음.
	}

	@PostMapping("/register")
	@PreAuthorize("isAuthenticated()") // 로그인한 사용자만 접근.
	public String register(BoardVO board, RedirectAttributes rttr) {
		// @Controller 어노테이션이 붙고,
		// 컴포넌트 스캔에 패키지가 지정되어 있다면,
		// 매개변수 인자들은 스프링이 자동으로 생성 할당 함.

//		if (board.getAttachList() != null) {
//			// 첨부파일이 있다면,
//			board.getAttachList().forEach(
//					attach -> log.info(attach));
//			// 첨부파일의 각 요소를 로그로 출력.
//		}		

		log.info("register : " + board);
		service.register(board);
		rttr.addFlashAttribute("result", board.getBno());
		// 리다이렉트 시키면서 1회용 값을 전달.

		return "redirect:/board/list";
	}

	// 제목 링크를 클릭하여 글 상세보기 - get 방식.
	@GetMapping({ "/get", "/modify" })
	public void get(@RequestParam("bno") Long bno, @ModelAttribute("cri") Criteria cri, Model model) {
		// @ModelAttribute("cri") 는 자동으로 객체 할당 전달.
		// 자동으로 생성된 Criteria cri를 모델값으로 저장하는데,
		// 저장명이 cri
		// 즉, model.addAttribute("cri", cri);// bno, pageNum, amount

		// @RequestParam : 요청 전달값으로 글번호 이용.
		log.info("/get");
		model.addAttribute("board", service.get(bno));
		// 전달값으로 명시만 하면 스프링이 자동 처리.
		// 사용하는 부분만 추가 구현.
	}

	// post 요청으로 /modify 가 온다면, 아래 메소드 수행.
	@PostMapping("/modify")
	@PreAuthorize("principal.username== #board.writer")
	public String modify(BoardVO board, Criteria cri, RedirectAttributes rttr) {

		log.info("modify:" + board);
		if (service.modify(board)) {
			rttr.addFlashAttribute("result", "success");
		}
		// 수정이 성공하면 success 메세지가 포함되어 이동.
		// 실패해도 메세지 빼고 이동.
		rttr.addAttribute("pageNum", cri.getPageNum());
		rttr.addAttribute("amount", cri.getAmount());
		// addFlashAttribute : 1회성, url 표시창에 전달되지 않음.
		// addAttribute : 지속, url 표시됨.
		rttr.addAttribute("type", cri.getType());
		rttr.addAttribute("keyword", cri.getKeyword());

		return "redirect:/board/list";
	}

	// 작성자와 로그인 계정이 일치한다면 게시물 삭제 가능.
	@PreAuthorize("principal.username== #writer")
	@PostMapping("/remove")
	public String remove(@RequestParam("bno") Long bno, Criteria cri
			, RedirectAttributes rttr, String writer) {

		log.info("remove..." + bno);
		List<BoardAttachVO> attachList = service.getAttachList(bno);

		if (service.remove(bno)) {
			deleteFiles(attachList);// 서버디스크의 파일 정보 삭제.
			rttr.addFlashAttribute("result", "success");
		}
//		rttr.addAttribute("pageNum", cri.getPageNum());
//		rttr.addAttribute("amount", cri.getAmount());
//		rttr.addAttribute("type", cri.getType());
//		rttr.addAttribute("keyword", cri.getKeyword());

		return "redirect:/board/list" + cri.getListLink();
	}

	@GetMapping(value = "/getAttachList", produces = MediaType.APPLICATION_JSON_VALUE)
	@ResponseBody
	public ResponseEntity<List<BoardAttachVO>> getAttachList(Long bno) {
		log.info("getAttachList: " + bno);
		return new ResponseEntity<>(service.getAttachList(bno), HttpStatus.OK);
	}

	private void deleteFiles(List<BoardAttachVO> attachList) {
		// 서버 특정 공간의 첨부파일 삭제 메소드
		if (attachList == null || attachList.size() == 0) {
			return;
		}

		log.info("delete attach file......");
		log.info(attachList);

		attachList.forEach(attach -> {
			try {
//				import java.nio.file.Files;
//				import java.nio.file.Path;
//				import java.nio.file.Paths;
				Path file = Paths.get(
						"c:\\upload\\" + attach.getUploadPath() + "\\" + attach.getUuid() + "_" + attach.getFileName());
				Files.deleteIfExists(file);
				// 해당 첨부파일이 존재한다면 삭제.
			} catch (Exception e) {
				e.printStackTrace();
			}
		});
	}

}
