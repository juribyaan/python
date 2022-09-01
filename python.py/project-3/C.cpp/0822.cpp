#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h> 
#include <iostream>


//인공지능 
//딥러딩 1공식 순전파/역전파
double x = 2 , w = 3 , b = 1;

int main() {

	double y = x * w + 1 * b;
	printf("y : %f\n" , y);

	return 0;
}

//2공식 평균제곱오차
E = (y-yT)*(y-yY)/2

오차 = 순전파에 의한 예측값 - 목표값 * /2

double x = 2 , 
w = 3 ,
b = 1 ,
yT = 10;

int main() {

	double y = x * w + 1 * b;

	double E = ( y - yT ) * ( y - yT ) / 2;	
	printf("E : %f\n" , E);

	return 0;
}

//3공식 역전파 오차
yE = y - yT

역전파 오차 = 순전파에 의한 예측값 -목표값(라벨,실제로 원하는 값)

double x = 2 , 
w = 3 ,
b = 1 ,
yT = 10;

int main() {

	double y = x * w + 1 * b;	
	double E = ( y - yT ) * ( y - yT ) / 2;	

	double yE = y - yT;
	printf("yE : %f\n" , yE);

	return 0;
}


//4공식 입력 역전파

xE = yE*w

입력 역전파 = 역전파 오차 * 

//5공식 편향 순전파,가중치

y=w*x+b*1

//6공식 편향 역전파,가중치
double x = 2 , 
w = 3 , 
b = 1 ,
yT = 10;

int main() {

	double y = x * w + 1 * b;
	printf("y : %f\n" , y);

	double E = ( y - yT ) * ( y - yT ) / 2;	
	printf("E : %f\n" , E);

	double yE = y - yT;
	printf("yE : %f\n" , yE);

	double wE = yE * x;
	double bE = yE * 1;
	printf("wE : %f, bE : %f\n" , wE , bE);

	return 0;
}

//7공식 신경망 학습
lr  학습률

//연습문제 1,2
int main() {
	double x1 , x2 , y1 , y2 , y3 , w1 , w2 , w3 , w4 , w5 , w6 , b1 , b2 , b3;

	x1 = 0.05;//초기값;
	x2 = 0.10;//초기값2;
//가중치
	w1 = 0.15;//학습값;
	w2 = 0.20;//학습값;
	w3 = 0.25;//학습값;
	w4 = 0.30;
	w5 = 0.40;
	w6 = 0.55;

	b1 = 1;//편향;
	b2 = 1;//편향2;
	b3 = 1;//편향3;

	double yT1 = 0.01;//기댓값;
	double yT2 = 0.99;//기댓값;
	double yT3 = 0.50;//기댓값;
	double ir = 0.01;//학습값
	for (int i = 0; i < 2000; i++){

		//결과값
		y1 = ( x1 * w1 ) + ( x2 * w2 ) + ( 1 * b1 );
	y2 = ( x1 * w3 ) + ( x2 * w4 ) + ( 1 * b2 );
	y3 = ( x1 * w5 ) + ( x2 * w6 ) + ( 1 * b3 );

	//오차값
	double E1 = ( y1 - yT1 ) * ( y1 - yT1 ) / 2;
	double E2 = ( y2 - yT2 ) * ( y2 - yT2 ) / 2;
	double E3 = ( y3 - yT3 ) * ( y3 - yT3 ) / 2;


	double E = E1 + E2 + E3;

	//역전파 오차
	double yE1 = ( y1 - yT1 );
	double yE2 = ( y2 - yT2 );
	double yE3 = ( y3 - yT3 );


	//입력 역전파
	double x1E = ( yE1 * w1 ) + ( yE2 * w3 ) + ( yE3 * w5 );
	double x2E = ( yE1 * w2 ) + ( yE2 * w4 ) + ( yE3 * w6 );
	//double bE = ( yE1 * b1 ) + ( yE2 * b2 ) + ( yE3 * b3 );

//가중치, 편향 역전파
	//y1 = ( w1 * x1 ) + ( w2 * x2 ) + ( b1 * 1 );
	//y2 = ( w3 * x1 ) + ( w4 * x2 ) + ( b2 * 1 );
	//y3 = ( w5 * x1 ) + ( w6 * x2 ) + ( b3 * 1 );

	double wE1 = yE1 * x1;
	double wE2 = yE1 * x2;
	double wE3 = yE2 * x1;
	double wE4 = yE2 * x2;
	double wE5 = yE3 * x1;
	double wE6 = yE3 * x2;

	double bE1 = yE1;
	double bE2 = yE2;
	double bE3 = yE3;
	//double bE = bE1 + bE2 + bE3; 이런거 아님.

//신경망 학습
	w1 -= ir * wE1;
	w2 -= ir * wE2;
	w3 -= ir * wE3;
	w4 -= ir * wE4;
	w5 -= ir * wE5;
	w6 -= ir * wE6;

	b1 -= ir * bE1;
	b2 -= ir * bE2;
	b3 -= ir * bE3;

	printf("%d\n" , i);
	printf("y1 ,y2 ,y3 = %6.3lf,%6.3lf,%6.3lf\n" , y1 , y2 , y3);
	printf("w1 ,w2 ,w3 = %6.3lf,%6.3lf,%6.3lf\n" , w1 , w2 , w3);
	printf("w4 ,w5 ,w6 = %6.3lf,%6.3lf,%6.3lf\n" , w4 , w5 , w6);
	printf("b1 ,b2 ,b3 = %6.3lf,%6.3lf,%6.3lf\n" , b1 , b2 , b3);

	if (E < 0.0000001) break;

}
	return 0;
}

//문제 2
int main() {
	double x1 , x2 ,x3, 
		y1 , y2 ,
		w1 , w2 , w3 , w4 , w5 , w6 , 
		b1 , b2 ;

	x1 = 0.02;//초기값;
	x2 = 0.05;//초기값2;
	x3 = 0.12;
//가중치
	w1 = 0.15;//학습값;
	w2 = 0.20;//학습값;
	w3 = 0.02;//학습값;
	w4 = 0.27;
	w5 = 0.37;
	w6 = 0.52;

	b1 = 0.12;//편향;
	b2 = 0.39;//편향2;
	

	double yT1 = 0.02;//기댓값;
	double yT2 = 0.98;//기댓값;

	double ir = 0.01;//학습값
	for (int i = 0; i < 2000; i++){

		//결과값
	y1 = ( x1 * w1 ) + ( x2 * w2 ) + (x3*w3) +( 1 * b1 );
	y2 = ( x1 * w3 ) + ( x2 * w5 ) + (x3*w6) +( 1 * b2 );
	

	//오차값
	double E1 = ( y1 - yT1 ) * ( y1 - yT1 ) / 2;
	double E2 = ( y2 - yT2 ) * ( y2 - yT2 ) / 2;
	


	double E = E1 + E2 ;

	//역전파 오차
	double yE1 = ( y1 - yT1 );
	double yE2 = ( y2 - yT2 );
	


	//입력 역전파
	double x1E = ( yE1 * w1 ) + ( yE2 * w3 );
	double x2E = ( yE1 * w2 ) + ( yE2 * w4 );
	double x3E = ( yE1 * w4 ) + ( yE2 * w6 );
	//double bE = ( yE1 * b1 ) + ( yE2 * b2 ) + ( yE3 * b3 );

//가중치, 편향 역전파

	double wE1 = yE1 * x1;
	double wE2 = yE1 * x2;
	double wE3 = yE1 * x3;
	double wE4 = yE2 * x1;
	double wE5 = yE2 * x2;
	double wE6 = yE2 * x3;

	double bE1 = yE1;
	double bE2 = yE2;
	
	//double bE = bE1 + bE2 + bE3; 이런거 아님.

//신경망 학습
	w1 -= ir * wE1;
	w2 -= ir * wE2;
	w3 -= ir * wE3;
	w4 -= ir * wE4;
	w5 -= ir * wE5;
	w6 -= ir * wE6;

	b1 -= ir * bE1;
	b2 -= ir * bE2;
	
	printf("%d\n" , i);
	printf("y1 ,y2 = %6.3lf,%6.3lf\n" , y1 , y2 );
	printf("w1 ,w2 ,w3 = %6.3lf,%6.3lf,%6.3lf\n" , w1 , w2 , w3);
	printf("w4 ,w5 ,w6 = %6.3lf,%6.3lf,%6.3lf\n" , w4 , w5 , w6);
	printf("b1 ,b2 = %6.3lf,%6.3lf\n" , b1 , b2 );

	if (E < 0.0000001) break;

}
	return 0;
}
#endif