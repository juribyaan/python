#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	FILE * fp = fopen ( "data.txt","w" );
	fprintf ( fp,"3!\n" ); //파일에 써라
	

	printf ( "Be happy\n");
	printf ( "12345678901234567890\n" );
	printf ( "My\tfriend\n");
	printf ( "Goot\bd\tchance\n" );
	printf ( "Cow\rW\a\n" );
	
	fprintf ( fp,"Be happy\n" );
	fprintf ( fp,"12345678901234567890\n" );
	fprintf ( fp,"My\tfriend\n" );
	fprintf ( fp,"Goot\bd\tchance\n" );
	fprintf ( fp,"Cow\rW\a\n" );

	printf ( "\n" );

	printf ( "%d\n",10 );
	printf ( "%lf\n",3.4 );
	printf ( "%.1lf\n",3.45 );
	printf ( "%.10lf\n",3.4 );

	printf ( "%d과 %d의 합은 %d입니다.\n",10,20,10+20 );
	printf ( "%.1lf-%.1lf = %.1lf\n",3.4, 1.2, 3.4-1.2 );

	fprintf ( fp,"\nfor문을 이용한 데이터 생성 저장\n" );
		for ( int i = 'a'; i<'z'; i++ ) {
			fprintf ( fp,"%c",i ); //문자열 반복 수행 입력
		};

	fprintf ( fp,"\n을 응용한 10줄 반복 생성\n" );

		for ( int n = 0; n<10; n++ ) {
			for ( int i = 'a'; i<='z'; i++ ) {
				fprintf ( fp,"%c",i );
					};
			fprintf ( fp,"\n" );
		};

		fprintf ( fp,"\n" );

		char istr [16]; //istr 이란 배열 지정
		for ( int i = 0; i<11; i++ ) {
			_itoa ( i,istr,10 ); //i 를 istr에 넣고 10진수로?
			                     //진법 정수값을 문자열로 전환해주는 함수. 배열이 필요함.  int to askicode 
			fprintf ( fp,"%s",istr );
			fprintf ( fp,"\n" );
			fprintf ( fp,"*%d",i ); //그냥 10진수의 문자열로 출력.
		}

		printf ( "2-6 실수 상수 표현법 p.40" );
		printf ( "%.1lf\n",1e6 );
		printf ( "%.7lf\n",3.14e-5 );
		printf ( "%le\n",0.0000314 );
		printf ( "%.2le\n",0.0000314 );

	fclose ( fp );
	
	system ( "pause" );

	return 0;
}




#endif







