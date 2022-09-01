#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void f1(int ip) {}
void f2(char strp[])[]

int main() {
	int ia = 3;
	f1(ip);

	char stra[5] = "3.14"
	f2(char stra); == f2(char& stra[0]); //같은 표기법.

	return 0;
}

//
void p_arr(int ary[]) {
	printf("sizeof(ary) = %d\n", sizeof(ary));//배열 주소 크기
	printf("%#x\n", &ary[0]);
} //배열은 주소값으로 전달함.
  //https://jhnyang.tistory.com/203 참고
int main() {
	int ary[5] = { 1,2,3,4,5 };
	printf("배열 전체 공간 크기 sizeof(ary) = %d\n", sizeof(ary)); 
	//배열이 차지하는 전체 공간의 크기

	printf("%#x\n", &ary[0]);
	printf("%#x\n", ary);

	p_arr(ary);

	return 0;
}

//주소연산자 &의 개념
int main() {
int a;
double b;
char c;

printf("int형 변수의 주소 : %p\n", &a);
printf("doulbe형 변수의 주소 : %u\n", &b);
printf("char형 변수의 주소 : %u\n", &c);

return 0;
}

//포인터와 * 연산자

int main() {
	int a;
	int* pa; // pa 는 공간.

	pa = &a; //pa라는 공간에 변수의 주소값을 넣음.
	*pa = 10; //pa가 가리키는 주소에 10을 넣음.
	pa[0] = 20; //pa의 0번 항목에 20을 넣는다.

	printf("포인터로 a 값 출력 : %d\n", *pa); //pa가 가진 주소값 ,가르키는 값
	printf("포인터로 a의 주소값을 가지는 값을 부름", *&a);
	printf("변수명으로 a 값 출력 : %d\n", a); //a의 값.
	printf("%p\n", &a); //&a 는 그냥 주소
	printf("%p\n", pa); //pa 는 주소값을 담은 변수.

	return 0;
}

//p.241
int main() {
	int a = 10, b = 15, total;
	double avg;
	int* pa, * pb;
	int* pt = &total;
	double* pg = &avg;

	pa = &a; 
	pb = &b;
	&a == pa; // 이건 증명될수 있지만 정의할수 없음.

	*pt = (*pa + *pb);
	*pg = (*pt / 2.0);


	printf("두 정수의 값 :%d,%d\n", *pa, *pb);
	printf("두 정수의 합 : %d\n", *pt);
	printf("두 정수의 평균 : %lf\n", *pg);

	return 0;
}

//p.249
int main() {
	char ch;
	int in;
	double db;

	char* pc;
	int* pi;
	double* pd;

	pc = &ch;
	pi = &in;
	pd = &db;

	printf("char   형 변수의 주소크기 %d\n", sizeof(&ch));
	printf("int    형 변수의 주소크기 %d\n", sizeof(&in));
	printf("double 형 변수의 주소크기 %d\n\n", sizeof(&db));

	printf("char   포인터 변수의 크기 %d\n", sizeof(pc));
	printf("int    포인터 변수의 크기 %d\n", sizeof(pi));
	printf("double 포인터 변수의 크기 %d\n\n", sizeof(pd));

	printf("char   포인터변수가 가리키는 변수의 크기 %d\n", sizeof(*pc));
	printf("int    포인터변수가 가리키는 변수의 크기 %d\n", sizeof(*pi));
	printf("double 포인터변수가 가리키는 변수의 크기 %d\n", sizeof(*pd));

	return 0;
}

//~p.256
void swap(int* pa, int* pb);

void swap(int* pa, int* pb) {
	int temp;

	temp = *pa;
	*pa = *pb;
	*pb = temp;
}

int main() {
	int a = 10, b = 20;
	printf("a = %d,b = %d\n\n", a, b);
	printf("&a = %p,&b = %p\n", &a, &b);

	swap(&a, &b);
	printf("a = %d, b = %d\n", a, b);
	printf("&a = %p , &b = %p\n\n", &a, &b);

	return 0;
}

//p.260문제

//3
int main() {
	int  a = 10, 
		 b = 20;

	int* pa = &a, 
	   * pb = &b,
	   * pt;

	pt = pa;
	pa = pb;
	pb = pt;
	printf("%d,%d", *pa, *pb);

	return 0;
}

//도전 예제 line_up을 완성해서 입력받은 값을 크기대로 출력
//뻘짓
void swap(double* pa, double* pb);
void line_up(double* maxp, double* midp, double* minp);

int main() {
	double max, mid, min;
	scanf("%lf%lf,%lf", &max, &mid, &min);
	line_up(&max, &mid, &min);
	printf("정렬된 값 출력 : %.1lf, %.1lf, %.1lf\n", max, mid, min);

	return 0;
}

void swap(double* pa, double* pb) {
	double temp;

	temp = *pa;
	*pa = *pb;
	*pb = temp;
};

void line_up(double* maxp, double* midp, double* minp) {
	double* a, * b, * c;


	if (a - b > 0 || a - c > 0) {
		*a = *maxp;
		if (b - c > 0) {
			*b = *midp;
			//pinrtf("%.1lf %.1lf %.1lf", a, b, c);
		}
		*c = *minp;
		//pinrtf("%.1lf %.1lf %.1lf", a, c, b);
	}
	else if (b - a > 0 || b - c > 0) {
		*b = *maxp;
		if (a - c > 0) {
			*a = *midp;
			//pinrtf("%.1lf %.1lf %.1lf", b, a, c);
		}
		*c = *minp;
		//pinrtf("%.1lf %.1lf %.1lf", b, c, a);

	}
	else if (c - a > 0 || c - b > 0) {
		*c = *maxp;
		if (a - b > 0) {
			*a = *midp;
			//pinrtf("%.1lf %.1lf %.1lf", c, a, b);
		}
		*b = *minp;
		//pinrtf("%.1lf %.1lf %.1lf", c, b, a);

	}

};

//뻘짓2
void line_up(double* maxp, double* midp, double* minp) {
	double* a, * b, * c;
	*maxp = *a;
	midp = &b;
	minp = &c;
	if (b > a) {
		swap(&a, &b);
	}
	else if (c > b) {
		swap(&b, &c);
	}


}

//뻘짓3
void line_up(double* maxp, double* midp, double* minp) {
	if (maxp > midp || maxp > minp) {
		if (midp > minp) {
			return;
		}
		else {
			swap(minp, midp);
		}
	}
	else if (midp > maxp || midp > minp) {
		if (maxp > minp) {
			return;
		}
		else {
			swap(minp, maxp);
		}
	}
	else if (minp > maxp || minp > midp) {
		if (maxp > midp) {
			swap(midp, maxp);
		}
	}
}

//

void line_up(double* maxp, double* midp, double* minp) {

	while (true) {

		if (*midp < *minp) {
			swap(midp, minp);
		}
		else if (*maxp < *minp) {
			swap(maxp, minp);
		}
		else {
			swap(maxp, midp);
		}
		break;
	}
}



//
int main() {
	int ary[3];
	int* ptr = &ary[0];

	*ptr = 10; // = *(ptr+0) = ptr[0]
	//ary = &ary[0] = *ary = *&ary[0] = ary[0] = *(ary+0) 같은 거임.

	//*(ary+i) == ary[i]
	//ary+i == &ary[i]

	printf("%d\n", ary[0]);

	*(ptr + 1) = 20;
	printf("%d\n", ary[1]);

	*(ptr + 2) = 30;
	printf("%d\n", ary[2]);
}

//p.265
int main() {
	int ary[3];
	int i;

	*(ary + 0) = 10;
	*(ary + 1) = *(ary + 0) + 10;

	printf("세번째 배열 요소에 키보드 입력 : ");
	scanf("%d", ary + 2);

	for (i = 0; i < 3; i++) {
		printf("%5d", *(ary + i));
	}
}

//p.268

int main() {
	int ary[3];
	int* pa = ary;
	int i;
	*pa = 10;
	*(pa + 1) = 20;
	pa[2] = pa[0] + pa[1];

	for (i = 0; i < 3; i++) {
		printf("%5d", pa[i]);
	}

	return 0;
}

//p.286

void input_ary(double* pa, int size);
double find_max(double* pa, int size);

int main() {
	double ary[5];
	double max;
	int size = sizeof(ary) / sizeof(&ary);

	input_ary(ary, size);//double*pa = ary
	max = find_max(ary, size);
	printf("배열의 최댓값 ; %.1lf\n", max);

	return 0;
}

void input_ary(double* pa, int size) {
	int i;
	printf("%d개의 실수값 입력 : ", size);
	for (i = 0; i < size; i++) {
		scanf("%lf", pa + i);
	}
};

double find_max(double* pa, int size) {
	double max;
	int i;

	max = pa[0];
	for (i = 1; i < size; i++) {
		if (pa[i] > max) max = pa[i];
	}
	return max;
};

//p.291
int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

void print_month(int* mp) {
	int i;
	for (i = 1; i < 13; i++) {
		printf("%5d", *(mp + i - 1));
		if (i % 5 == 0) printf("\n");
	}
}
int main() {
	print_month(month);
}

//p.292
void input_nums(int* lotto_nums);
void print_nums(int* lotto_nums);

int main() {
	int lotto_nums[6];

	input_nums(lotto_nums);
	print_nums(lotto_nums);

	return 0;
}

void input_nums(int* lotto_nums) {
	for (int i = 0; i < 6; i++) {
		scanf("번호입력", &lotto_nums);


		//	printf("같은 번호가 있습니다.");


	}

};

void print_nums(int* lotto_nums) {
	for (int i = 0; i < 6; i++) {
		printf("로또 번호 : ", lotto_nums[i]);
	}
	return;
};

#endif