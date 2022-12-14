/**
 * 
 */
 
console.log("Reply module......");

var replyService = (function() {// 자바스크립트는 함수를 변수에 할당 가능.
	function add(reply, callback, error) {
		// reply : 덧글 객체,
		// callback : 덧글 등록후 수행할 메소드. 비동기.
		// 주문과 동시에 처리할 내용도 전달. 페이지 이동없이 새로운 내용 갱신.
		console.log("add reply......");
		$.ajax({
			type: 'post',
			url: '/replies/new',
			data: JSON.stringify(reply),
			// 전달 받은 객체를 json 으로 변환.
			contentType: "application/json; charset=utf-8",
			success: function(result,status, xhr) {
				if (callback) {
					callback(status); 
				}
			},
			error: function(xhr, status, er) {
				if (error) {
					error(er);
				}
			}
		});
	}
	
	// 댓글 목록 가져오기.
	function getList(param, callback, error) {
		console.log("getList......");
		var bno = param.bno;
		var page = param.page || 1;
		// 페이지 번호가 있으면 페이지 번호 전달 없으면 1전달.
		$.getJSON("/replies/pages/" + bno + "/" + page,
				function(data) {
					if (callback) {
						//callback(data);
						callback(data.replyTotalCnt, data.list);
					}
				}).fail(function(xhr, status, err) {
			// xhr : xml http request 의 약자.
			// 현재는 사용되지 않고, 형식만 맞춰줌.
			if (error) {
				error(er);
			}
		});
	}	
	
	// 댓글 시간 표시.
	function displayTime(timeValue){
		var today=new Date();// 현재 시간
		var gap = today.getTime() - timeValue;
		// 시간차이 연산.
		var dateObj = new Date(timeValue);
		// 덧글이 등록된 시간을 변수에 할당..
		var str="";
		
		if(gap<(1000*60*60*24)){ 
			// 시간차이가 24시간 미만이라면,
			var hh=dateObj.getHours();
			var mi=dateObj.getMinutes();
			var ss=dateObj.getSeconds();
			
			return [ (hh>9?'':'0')+hh, ':'
				,(mi>9?'':'0')+mi
				,':',(ss>9?'':'0')+ss].join('');
			// 배열 요소를 문자열로 변환. join
			// 시간에 포맷을 맞추기 위해서
			// 0~9까지는 앞에 0을 추가 표시.
		}else{
			var yy=dateObj.getFullYear();
			var mm=dateObj.getMonth()+1;
			var dd=dateObj.getDate();
			
			return [yy,'/', (mm>9?'':'0')+mm,'/',
				(dd>9?'':'0')+dd].join('');
		}
	}
	
	function get(rno, callback, error) {
		$.get("/replies/" + rno, function(result) {
			if (callback) {
				callback(result);
			}
		}).fail(function(xhr, status, er) {
			if (error) {
				error(er);
			}
		});
	}	
	
	function update(reply, callback, error) {
		console.log("rno: " + reply.rno);
		$.ajax({
			type : 'put',
			url : '/replies/' + reply.rno,
			data : JSON.stringify(reply),
			contentType : "application/json;charset=utf-8",
			success : function(result, status, xhr) {
				if (callback) {
					callback(result);
				}
			},
			error : function(xhr, status, er) {
				if (error) {
					error(er);
				}
			}
		});
	}
	
	// 덧글 삭제
	function remove(rno, replyer, callback, error) {
		$.ajax({
			type : 'delete',
			url : '/replies/' + rno,
			
			data:JSON.stringify({rno:rno,replyer:replyer}),
		 	contentType : "application/json; charset=utf-8",			
			
			success : function(deleteResult, status, xhr) {
				if (callback) {
					callback(deleteResult);
				}
			},
			error : function(xhr, status, er) {
				if (error) {
					error(er);
				}
			}
		});
	}			

	return {
		remove: remove,
		update: update,
		add: add,
		getList: getList,
		displayTime: displayTime,
		get: get
	};
})(); // 즉시 실행 함수: 명시하는 것과 동시에 메모리에 등록.

 