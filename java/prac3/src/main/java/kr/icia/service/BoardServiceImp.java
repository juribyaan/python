package kr.icia.service;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import kr.icia.domain.BoardAttachVO;
import kr.icia.domain.BoardVO;
import kr.icia.domain.Criteria;
import kr.icia.mapper.BoardAttachMapper;
import kr.icia.mapper.BoardMapper;
import kr.icia.mapper.ReplyMapper;
import lombok.Setter;
import lombok.extern.log4j.Log4j;

@Log4j // lombok 로그 이용.
@Service // 이 클래스가 서비스 계층을 맡는다고 알림.
//@AllArgsConstructor // 모든 매개변수에 대한 생성자 1개 생성.(생성자 여러개 아님)
public class BoardServiceImp implements BoardService {
	@Setter(onMethod_ = @Autowired)
	private BoardMapper mapper;

	@Setter(onMethod_ = @Autowired)
	private BoardAttachMapper attachMapper;
	// 글 등록시 첨부파일이 있다면, 첨부 파일의 정보도 디비에 등록 되야 함.

	@Setter(onMethod_ = @Autowired)
	private ReplyMapper replyMapper;// 덧글

	@Transactional
	@Override
	public void register(BoardVO board) {
		log.info("register......" + board);
		mapper.insertSelectKey(board);

		if (board.getAttachList() == null || board.getAttachList().size() <= 0) {
			// 첨부파일이 없다면 종료.
			return;
		}

		board.getAttachList().forEach(attach -> {
			attach.setBno(board.getBno());
			// BoardAttachVO 의 객체 attach
			attachMapper.insert(attach);
		});
	}

	@Override
	public BoardVO get(Long bno) {
		log.info("get......" + bno);
		return mapper.read(bno);
	}

	@Transactional
	@Override
	public boolean modify(BoardVO board) {
		log.info("modify......" + board);

		boolean modifyResult = false; // 게시물 수정 성공 여부.
		modifyResult = mapper.update(board) == 1;

		int attachList = 0;// 첨부파일 갯수.
		if (board.getAttachList() != null) {// 첨부파일이 있다면,
			attachList = board.getAttachList().size();
		}

		// 게시물이 수정 성공하고, 첨부파일이 있다면,
		if (modifyResult && attachList > 0) {
			// 등록하려는 첨부파일 목록(11,22)
			List<BoardAttachVO> inputList = board.getAttachList();
			// 디비에 등록되어 있는 첨부파일 목록(22,33)
			List<BoardAttachVO> dbList = attachMapper.findByBno(board.getBno());

			for (BoardAttachVO bav : inputList) {
				boolean flag = false;

				for (BoardAttachVO bav2 : dbList) {
					if (bav.getFileName().equals(bav2.getFileName())) {
						flag = true;// 중복 이름 확인.
					}
				}

				// 중복되지 않았다면 디비에 등록.
				if (!flag) {
					bav.setBno(board.getBno());
					attachMapper.insert(bav);
				}
			}
		}

		return modifyResult;
	}

	@Transactional
	@Override
	public boolean remove(Long bno) {
		log.info("remove......" + bno);
		attachMapper.deleteAll(bno); // 첨부파일 정보 삭제
		replyMapper.deleteAll(bno); // 덧글 삭제

		return (mapper.delete(bno)) == 1;// 게시글 삭제.
	}

//	@Override
//	public List<BoardVO> getList() {
//		log.info("getList......");
//		return mapper.getList();
//	}

	@Override
	public List<BoardVO> getList(Criteria cri) {
		log.info("getListWithPaging....." + cri);

		return mapper.getListWithPaging(cri);

	}

	@Override
	public int getTotal(Criteria cri) {
		log.info("get total count");
		return mapper.getTotalCount(cri);

	}

	@Override
	public List<BoardAttachVO> getAttachList(Long bno) {
		log.info("get Attach list by bno: " + bno);
		return attachMapper.findByBno(bno);
		// 게시물 번호를 전달하고,
		// 게시물 번호와 일치하는 첨부파일을 모두 리턴.

	}

}
