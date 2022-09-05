package kr.icia.domain;

import lombok.Data;

@Data
public class AttachFileDTO {
	// 첨부파일 1개에 대한 처리.
	private String fileName;
	private String uploadPath;
	private String uuid;
	private boolean image;
}

