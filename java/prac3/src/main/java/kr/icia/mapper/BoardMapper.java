package kr.icia.mapper;

import java.util.List;

import org.apache.ibatis.annotations.Param;

import kr.icia.domain.BoardVO;
import kr.icia.domain.Criteria;

public interface BoardMapper {
	public List<BoardVO> getList();
	// 게시물 목록 가져오기.

	public void insert(BoardVO board);
	// bno 는 시퀀스 자동 생성으로 나머지 값만 입력.
	// 새로운 게시물 1개 추가.

	public void insertSelectKey(BoardVO board);
	// 생성되는 시퀀스 값을 확인하고 나머지 값 입력.
	// 새로운 게시물 1개 추가의 다른 방식.

	public BoardVO read(Long bno);
	// 게시물 내용 읽기

	public int delete(Long bno);
	// 게시물 삭제

	public int update(BoardVO board);
	// 게시물 수정.

	// crud: create(insert) read(select) update delete
	public List<BoardVO> getListWithPaging(Criteria cri);

	public int getTotalCount(Criteria cri);
	// 총 게시물 갯수 파악.

	public void updateReplyCnt(@Param("bno") Long bno
			, @Param("amount") int amount);

}
