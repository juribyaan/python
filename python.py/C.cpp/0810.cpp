#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

enum season{spring='a',summer,fall,winter };

int main ( void ) {

	int a = 0,b = 0;

	if ( a>0 ) {
		b = 1;
	} else if ( a==0 ) {
		b = 2;
	} else {
		b = 3;
	};

	printf ( "b = %d\n",b );
	

	//135페이지 연습문제

	if ( a<0 ) {
		a = -a;
	};

	if ( a%2==0 ) {
		a = 2;
	} else {
		a = 1;
	};

	//
	int chest = 95;
	char size;
	if ( chest <= 90 ) {
		size = 'S';
	} else if ( 90<chest<=100 ) {
		size = 'M';
	} else if ( chest>100 ) {
		size = 'L';
	};
	printf ( "%c",size );

	//
	double height = 179.5,weight = 75.0;
	if ( height>=187.5&&weight<80.0 ) {
		printf ( "\nok\n" );
	} else {
		printf ( "\ncancel\n" );
	};

	//p.145 스위치 예제
	int rank = 2,m = 0;
	switch ( rank ) {
		case 1:
			m = 300;
			break;
		case 2:
			m = 200;
			break;
		case 3:
			m = 100;
			break;
		default:
			m = 10;
			break;
	}
	printf ( "m = %d\n",m );

	//배열 숫자에 이름을 붙여줄수 있다. 영문,숫자 지정도 가능.
	//enum season{spring,summer,fall,winter=10 }; 메인 위에 선언 해놓고
	//구조체로써 변수를 넣음.
	struct season2 {	};
	//
	union season3{  };
	printf ( "%d",spring );
	printf ( "%d",summer );
	printf ( "%d",fall );
	printf ( "%d\n",winter );

	//printf ( "%s",spring );
	
	char ss;
	printf ( "계절을 입력해주세요(a-봄,b-여름,c-가을,d-겨울)" );
	scanf ( "%c",&ss );

	switch ( ss ) {
		case spring:printf ( "spring" ); break;
		case summer:printf ( "summer" ); break;
		case fall:printf ( "fall" ); break;
		case winter:printf ( "winter" ); break;
		default:break;
	}

	//
	//연습문제 150~152
	//

	//몫이 0이면 참 1이면 거짓
	int n;
	printf ( "정수입력 : " );
	scanf ( "%d",&n );
	switch ( n%3 ) {
		case 0:
			printf ( "참" );
			break;
		case 1:
			printf ( "거짓" );
			break;
	};

	//옷 사이즈 측정

	int age = 25,
		chest = 95;
	char size;
	if ( age<20 ) {
		if ( chest>85 ) {
			size = 'S';
		} else if ( chest>95 ) {
			size = 'M';
		} else {
			size = 'L';
		}
	} else {
		if ( chest<90 ) {
			size = 'S';
		} else if ( chest<100 ) {
			size = 'M';
		} else {
			size = 'L';
		}
	};
	printf ( "사이즈는 %c\n",size );
	return 0;

	//계산기

	int a,b,d;
	char c;
	scanf ( "%d %c %d",&a,&c,&b );
	if ( c=='+' ) {
		d = (a+b);
	} else if ( c=='-' ) {
		d = (a-b);
	} else if ( c=='*' ) {
		d = (a*b);
	} else if ( c=='/' ) {
		d = (a/b);
	};
	printf ( "%d %c %d = %d ",a,c,b,d );

	return 0;

	//

	return 0;

};

#endif