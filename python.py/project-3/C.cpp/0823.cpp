#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h> 
#include <iostream>

#if 0
#pragma once // 중복시 1번만 하는 명령어
//순전파
void for_Y(double *X , double *W , double *B , double *Y , int M , int N);
//오차
double calculate_MSE(double *Y , double *YT , int N);
//역전파 오차
void back_YE(double *YE , double *Y , double *YT , int N);
//가중치 역전파
void back_WE(double *WE , double *X , double *YE , int M , int N);
//편향 역전파
void back_BE(double *BE , double *YE , int N);
//가중치 학습
void learning_W(double *W , double lr , double *WE , int M , int N);
//편향 학습
void learning_B(double *B , double lr , double *BE , int N);
//순전파 출력
void print(const char *s , double *Y , int N);
//가중 역전파 출력
void print(const char *s , double *W , int M , int N);

void backward_HE(double *HE , double *W , double *YE , int M , int N);


#include "mydnn.h"
#include <stdio.h>
//순전파
void for_Y(double *X , double *W , double *B , double *Y , int M , int N) {
	               //double (*w)[n]
	for (int n = 0; n < N; n++) Y[n] = 0;
	for (int m = 0; m < M; m++) {
		for (int n = 0; n < N; n++) {
			Y[n] += X[m] * W[m * N + n];//W[m][m]
		}
	}
	for (int n = 0; n < N; n++) Y[n] += B[n];
};






//오차
double calculate_MSE(double *Y , double *YT , int N) {
	double E = 0;
	for (int n = 0; n < N; n++) {
		E += ( Y[n] - YT[n] ) * ( Y[n] - YT[n] ) / 2;
	};
	return E;
};

//역전파 오차
void back_YE(double *YE , double *Y , double *YT , int  N) {
	for (int n = 0; n < N; n++) {
		YE[n] = Y[n] - YT[n];
	};
};

//가중치 역전파
void back_WE(double *WE , double *X , double *YE , int M , int N) {
	for (int m = 0; m < M; m++) {
		for (int n = 0; n < N; n++) {
			WE[m * N + n] = X[m] * YE[n];
		};
	};
};

//편향 역전파
void back_BE(double *BE , double *YE , int N) {
	for (int n = 0; n < N; n++);
};

//가중치 학습
void learning_W(double *W , double lr , double *WE , int M , int N) {
	for (int m = 0; m < M; m++) {
		for (int n = 0; n < N; n++) {
			W[m * N + n] -= lr * WE[m * N + n];
		};
	};
};

//편향 학습
void learning_B(double *B , double lr , double *BE , int N) {
	for (int n = 0; n < N; n++) {
		B[n] -= lr * BE[n];
	};
};

//순전파 출력
void print(const char *s , double *Y , int N) {
	printf("%s [" , s);
	for (int n = 0; n < N - 1; n++) {
		printf("%.3lf " , Y[n]);
		printf("%.3lf]\n" , Y[N - 1]);
	};
};

//순전파 출력 함수
/*void dnn_test_Y() {
	for_Y(X , (double *)W , B , Y , M , N);
	        // &W[M] *[N];
	print_YT("Y = " , Y , N);

};
*/

//역전파 출력 함수
/*
void dnn_test_WE() {
	back_WE( (double *) WE , X , YE , M , N);
	print_WE("WE =" , (double *) WE , M , N);
};
*/

//가중 역전파 출력
void print(const char *s , double *W , int M , int N) {
	printf("%s [\n" , s);
	for (int m = 0; m < M; m++) {
		printf("[" , s);
		for (int n = 0; n < N - 1; n++) {
			printf("%.3f " , W[m * N + n]);
		};
		printf("%.3f]\n" , W[m * N + N - 1]);
	};
	printf("]\n");
};
void backward_HE(double *HE, double *W, double *YE, int M, int N) {
for(int m=0;m<M;m++) HE[m] = 0;
for(int m=0;m<M;m++)
for(int n=0;n<N;n++) 05 HE[m] += YE[n]*W[m*N+n];
}

void print(char * s, double *Y, int N) {
printf("%s [", s);
for(int n=0;n<N-1;n++) printf("%.3f ", Y[n]);
printf("%.3f]\n", Y[N-1]);
}




const int M = 2 , O = 2 , N = 2;
double lr = 0.01;
double X[M] = { 0.05 , 0.10 };
double H[O];
double Y[N];
double YT[N] = { 0.01 , 0.99 };

//double W[M][N] = { {3,5},{4,6} };
double WH[M][O] = { { 0.15 , 0.25 } ,
	                { 0.20 , 0.30 } };
//double B[N] = { 1,2 };
double BH[O] = { 0.35 , 0.35 };

//double X[N] = {2,3};
double BY[O][N] { { 0.40 , 0.50 } ,
				 { 0.45 , 0.55 } };
double YE[N];
double BYE[N];
double WHE
double WYE[M][N];
double BHE[N];

void dnn_test() {

	for (int epoch = 0; epoch < 1000; epoch++) {

		printf("\nepoch = %d\n" , epoch);

		for_Y(X , (double *)W , B , Y , M , N);
		print("Y =" , Y , N);

		double E = calculate_MSE(Y , YT , N);
		printf("E = %.7f\n" , E);

		back_YE(YE , Y , YT , N);
		print("YE =" , YE , N);

		back_WE((double *)WE , X , YE , M , N);
		print("WE =" , (double *)WE , M , N);

		back_BE(BE , YE , N);
		print("BE =" , BE , N);

		double lr = 0.01;
		learning_W((double *)W , lr , (double *)WE , M , N);
		print("W =" , (double *)W , M , N);

		learning_B(B , lr , BE , N);
		print("B =" , B , N);
	}

}

int main() {

	dnn_test();

	return 0;
};

#endif