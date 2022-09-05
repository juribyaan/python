package kr.icia.domain;

import lombok.Data;

@Data
public class BoardAttachVO {
	// 1대 다 구조에서 어느 게시물의 첨부파일인지 처리.
	private String uuid;
	private String uploadPath;
	private String fileName;
	private boolean fileType;
	private Long bno;
}
