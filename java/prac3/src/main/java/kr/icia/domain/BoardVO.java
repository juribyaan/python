package kr.icia.domain;

import java.util.Date;
import java.util.List;

import lombok.Data;

//셋터, 겟터, equals, toString 등 자동 생성.
@Data
public class BoardVO {
	private Long bno;
	private String title;
	private String content;
	private String writer;
	private Date regdate;
	private Date updateDate;
	
	private int replyCnt;
	private List<BoardAttachVO> attachList;
}
