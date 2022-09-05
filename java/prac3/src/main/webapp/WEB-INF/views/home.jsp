<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/fmt" prefix="fmt"%>

<%@ include file="includes/header.jsp"%>

<script>
	self.location = "/board/list";
</script>
<!-- 로그아웃 처리시 /로 이동하고, homeController 에 의하여,
home.jsp 로 넘어온다면, 다시 /board/list 로 이동. -->

<%@ include file="includes/footer.jsp"%>