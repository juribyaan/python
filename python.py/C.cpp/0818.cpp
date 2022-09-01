#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h> 

//int* ipa[10000] ->& ipa[0]->func(ipa) -> int** (int**)->배열처리[i][j]

#include <stdio.h>
void encryption(int** ipp);
int main() {
	int ia0[10000] = { 1, };
	int ia1[10000] = { 2, };
	int ia2[10000] = { 3, };
	int* ipa[10000] = { ia0, ia1, ia2, };// &ia0[0]
	encryption(ipa);
	printf("%d %d %d", ipa[0][0], ipa[1][0], ipa[2][0]);
}
void encryption(int** ipp) {
	ipp[0][0]++;
	ipp[1][0]++;
	ipp[2][0]++;
}

// C가 어렵게 느껴지는 부분
// 배열 ->&(주소값)-> 함수 ->*(주소변수)-> |포인터| -> 배열처리(읽고, 수정)[i]
// 1// int ia[10000] -> &ia[0] -> func(ia) -> int * 
void encyption(int* ip, int n);

int main() {
	int ia[10000] = { 1,2,3, };
	encyption(ia, 10000);// int * ip = ia
	printf("%d %d %d %d\n", ia[0], ia[1], ia[2], ia[3]);
}

void encyption(int* ip, int n) {
	for (int i = 0; i < n; i++) ip[i]++;
}

// 2// int* ipa[10000] -> &ipa[0] -> func(ipa) -> int* * (int **) -> 배열처리[i][j]

void encryption(int** ipp);

int main() {
	int ia0[10000] = { 1, };
	int ia1[10000] = { 2, };
	int ia2[10000] = { 3, };
	int* ipa[10000] = { ia0, ia1, ia2, };// &ia0[0]
	encryption(ipa);
	printf("%d %d %d", ipa[0][0], ipa[1][0], ipa[2][0]);
}

void encryption(int** ipp) {
	ipp[0][0]++; // ipp[0][0] = ipp[0][0] + 1
	ipp[1][0]++;
	ipp[2][0]++;
}

// 3// int iaa[100][200] -> &iaa[0] -> func(iaa) -> int[200] * (int(*)[200]) -> 배열처리[i][j]

void encryption(int(*iap)[200]);

int main() {
	int iaa[100][200] = { {1,},{2,},{3,}, };
	encryption(iaa);
	printf("%d %d %d\n", iaa[0][0], iaa[1][0], iaa[2][0]);
}

void encryption(int(*iap)[200]) {
	iap[0][0]++; iap[1][0]++; iap[2][0]++;
}


// 1을 멀록으로 대체
void encyption(int* ip, int n);

int main() {
	// int ia[10000] = { 1,2,3, }; 전역공간스택을 잡아먹으니 멀뤅으로 대체
	int* ia = (int*)malloc(sizeof(int) * 10000); //힙으로 보내서 사용
	//ㄴ로 받음 ㄴ정수 변수의 주소변수선언문    ㄴ이만큼 공간 설정
	ia[0] = 1, ia[1] = 2, ia[2] = 3;//file input
	encyption(ia, 10000);// int * ip = ia
	printf("%d %d %d %d\n", ia[0], ia[1], ia[2], ia[3]);
	free(ia); //멀록이 쓰는 메모리의 종료 선언
}

void encyption(int* ip, int n) {
	for (int i = 0; i < n; i++) ip[i]++;
}

// 2를 멀록
void encryption(int** ipp);

int main() {

	//int ia0[10000] = { 1, };
	int* ia0 = (int*)malloc(sizeof(int) * 10000); ia0[0] = 1;
	//int ia1[10000] = { 2, };
	int* ia1 = (int*)malloc(sizeof(int) * 10000); ia1[0] = 2;
	//int ia2[10000] = { 3, };
	int* ia2 = (int*)malloc(sizeof(int) * 10000); ia2[0] = 3;
	//int* ipa[10000] = { ia0, ia1, ia2, };// &ia0[0]
	int** ipa = (int**)malloc(sizeof(int*) * 10000);
	ipa[0] = ia0, ipa[1] = ia1, ipa[2] = ia2;
	encryption(ipa);
	printf("%d %d %d", ipa[0][0], ipa[1][0], ipa[2][0]);

	free(ia0), free(ia1), free(ia2), free(ipa);
}

void encryption(int** ipp) {
	ipp[0][0]++; // ipp[0][0] = ipp[0][0] + 1
	ipp[1][0]++;
	ipp[2][0]++;
}

// 3을 멀럭
void encryption(int(*iap)[200]);

int main() {

	//int iaa[100][200] = { {1,},{2,},{3,}, };
	int(*iaa)[200] = (int(*)[200])malloc(sizeof(int) * 200 * 100);
	iaa[0][0] = 1, iaa[1][0] = 2, iaa[2][0] = 3;
	encryption(iaa);
	printf("%d %d %d\n", iaa[0][0], iaa[1][0], iaa[2][0]);
}

void encryption(int(*iap)[200]) {
	iap[0][0]++; iap[1][0]++; iap[2][0]++;
}

//p.454
int main(void) {
	int* pi;
	int i, sum = 0;

	pi = (int*)malloc(5 * sizeof(int));

	if (pi == NULL) {
		printf("메모리가 부족합니다!\n");
		exit(1);
	}

	printf("다섯 명의 나이를 입력하세요 : ");

	for (i = 0; i < 5; i++) {
		scanf("%d", &pi[i]);
		sum += pi[i];
	}

	printf("다섯 명의  평균 나이 : %.1lf\n", (sum / 5.0));
	free(pi);

	return 0;
}

//p.456

int main() {
	int* pi;
	int size = 5, count = 0, num, i;

	pi = (int*)calloc(size, sizeof(int));
	while (1) {
		printf("양수만 입력하세요 => ");
		scanf("%d", &num);
		if (num <= 0) {
			break;
		}
		if (count == size) {
			size += 5;
			pi = (int*)realloc(pi, size * sizeof(int));
		}
		pi[count++] = num;
	}

	for (i = 0; i < count; i++) {
		printf("%5d", pi[i]);
	}
	free(pi);

	return 0;
}

//p.466

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h> //동적 할당 헤더


void print_str(char** ps);

int main(void) {

	char temp[80];
	char* str[21] = { 0 };
	int i = 0;

	while (i < 20) {
		printf("문자열을 입력하세요 :");
		gets_s(temp);
		if (strcmp(temp, "end") == 0) {
			break;
		}
		str[i] = (char*)malloc(strlen(temp) + 1);
		strcpy(str[i], temp);
		i++;
	}

	print_str(str);

	for (i = 0; str[i] != NULL; i++) {
		free(str[i]);
	}

	return 0;
}

void print_str(char** ps) {
	while (*ps != NULL) {
		printf("%s\n", *ps);
		ps++;
	}
}

//p.469

int main(int argc, char** argv) {

	int i;

	for (i = 0; i < argc; i++) {
		printf("%s\n", argv[i]);
	}

	return 0;
}

//p.476 구조체
struct student {
	int num;
	double grade;
};

int main() {
	struct  student s1;

	s1.num = 2;
	s1.grade = 2.7;

	printf("학번 : %d\n", s1.num);
	printf("학점 : %.1lf", s1.grade);

	return 0;

};

//p.481
struct profile {
	char name[20];
	int age;
	double height;
	char* intro;
};

int main(void) {
	struct profile yuni;

	strcpy(yuni.name, "서하윤");
	yuni.age = 17;
	yuni.height = 164.5;

	yuni.intro = (char*)malloc(80);
	printf("자기소개 :");
	gets_s(yuni.intro, 80);

	printf("이름 : %s\n", yuni.name);
	pritnf("나이 : %d\n", yuni.age);
	pritnf("키 : %.1lf\n", yuni.height);
	pritnf("자기소개 : %s\n", yuni.intro);

	free(yuni.intro);

	return 0;
};

//구조체 변수를 넘길떄 주의
struct Name { char name[1000]; };
struct Name name;
void func(struct Name* name) {
	printf("%d", sizeof(name));
}

int main() {
	func(&name);
}

//p.492
struct score {
	int kor;
	int eng;
	int math;
};

int main() {
	struct score yuni = { 90,80,70 };
	struct score* ps = &yuni;

	printf("국어 : %d\n", (*ps).kor);
	printf("국어 : %d\n", yuni.kor);
	printf("영어 : %d\n", ps->eng);
	printf("수학 : %d\n", ps->math);
};

//p.497 구조체 배열 중요
struct address {
	char name[20];
	int age;
	char tel[20];
	char add[80];
};

void print_list(struct address* lp);

int main() {
	struct address list[5] = {
		{"홍길동",23,"111-1111","울릉도 독도"},
		{"이순신",35,"222-2222","서울 건천동"},
		{"장보고",19,"333-3333","완도 청해진"},
		{"유관순",15,"444-4444","충남 천안"},
		{"안중근",45,"555-5555","울릉도 해주"}
	};

	int i;

	for (i = 0; i < 5; i++) {
		printf("%10s%5d%15s%20s\n",
			list[i].name, list[i].age, list[i].tel, list[i].add);
	};

	printf("\n\n");

	print_list(list);

	return 0;

}

void print_list(struct address* lp) {
	int i;

	for (i = 0; i < 5; i++) {
		printf("%10s%5d%15s%20s\n",
			lp[i].name, (*(lp + i)).age, (lp + i)->tel, (&lp[i])->add);
	};
};

//p.499
struct list {
	int num;
	struct list* next;
};

int main() {
	struct list a = { 10,0 },
				b = { 20,0 }, 
				c = { 30,0 };

	struct list* head = &a,
			   * current;

	a.next = &b;
	b.next = &c;

	printf("head ->num : %d\n", head->num);
	printf("a.num : %d\n", a.num);

	printf("head ->next ->num : %d\n", head->next->num);
	printf("a.next : %d\n", head->next);

	printf("list all : ");
	current = head;
	while (current != NULL) {
		printf("%d ", current->num);
		current = current->next;
	}
	printf("\n");

	return 0;


https://carrotclub.tistory.com/20 이거 뭐지
https://modoocode.com/18

#endif