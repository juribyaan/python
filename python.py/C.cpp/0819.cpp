#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h> 
#include <iostream>

//
struct list {
   int data;
   struct list* next;
};
struct list data_list[10];
void init_list(struct list* listp, int size);
struct list * get_list_end(struct list* data_list);
int main() {
   init_list(data_list, sizeof(data_list)/sizeof(data_list[0]));
   struct list* end = get_list_end(data_list);
}
void init_list(struct list* listp, int size) {}
struct list* get_list_end(struct list* data_list) { return NULL; }

/*1.struct list 선언하면서 재귀함수로 링크 만들고
2.list의 배열을 선언하고 list data_list[10];
3.lnit_list();라는 함수 쓸거라 선언하고 받는 인수는 list의 포인터변수, int
4.list의 포인터 변수 *get_list_end선언 (struct list의 포인터 변수*data_list선언);

5.main에서 3번 호출 (data_list, sizeof(data_list)/sizeof(data_list[0]);
                          2번의 주소 , 2번의 크기
6.struct list*end 는 4번 get_list_end(data_list) 

7.3번은 list 크기 재고 끝
8.4번은*/ 

//
struct list {
   int data;
   struct list* next;
};
struct list data_list[10];
void init_list(struct list* listp, int size);
struct list * get_list_end(struct list* data_list);

int main() {

   init_list(data_list, sizeof(data_list)/sizeof(data_list[0]));
   struct list* end = get_list_end(data_list);
}

void init_list(struct list* listp, int size) {
   for (int i = 0; i < size; i++) {
      listp[i].data = i;
      if (i < size - 1) listp[i].next = &listp[i + 1];
      else if (i == size - 1) listp[i].next = NULL;
      printf("list[%d]:%d@%p %#x->%#x\n", 
          i, listp[i].data, &listp[i],listp[i].next);
   }
}
struct list *get_list_end(struct list *data_list) { return NULL; }

//
struct list {
   int data;
   struct list* next;
};
struct list data_list[100000000];
void init_list(struct list* listp, int size);
struct list * get_list_end(struct list* data_list);
int main() {
   init_list(data_list, sizeof(data_list)/sizeof(data_list[0]));
   struct list* end = get_list_end(data_list);
}
void init_list(struct list* listp, int size) {
   for (int i = 0; i < size; i++) {
      listp[i].data = i;
      if (i < size - 1) listp[i].next = &listp[i + 1];
      else if (i == size - 1) listp[i].next = NULL;
      if(i==size-1)
      printf("list[%d]:%d@%#x->%#x\n", 
         i, listp[i].data, &listp[i], listp[i].next);
   }
}
struct list* get_list_end(struct list* listp) {
   int i;
   for (i = 0; listp[i].next != NULL; listp = listp->next) {}
   printf("list[%d]:%d@%#x->%#x\n",
      i, listp[i].data, &listp[i], listp[i].next);
   return listp;
}

//
struct list {
   int data;
   struct list* next;
};
#define NODE_NUM 1000000000//3
//struct list data_list[100000000];
struct list* data_list = NULL;//2
void init_list(struct list* listp, int size);
struct list * get_list_end(struct list* data_list);
int main() {
   data_list = (struct list*)malloc(sizeof(struct list) * NODE_NUM);//1
   init_list(data_list, NODE_NUM);// sizeof(data_list) / sizeof(data_list[0]));
   struct list* end = get_list_end(data_list);
}
void init_list(struct list* listp, int size) {
   for (int i = 0; i < size; i++) {
      listp[i].data = i;
      if (i < size - 1) listp[i].next = &listp[i + 1];
      else if (i == size - 1) listp[i].next = NULL;
      if(i==size-1)
      printf("list[%d]:%d@%#x->%#x\n", 
         i, listp[i].data, &listp[i], listp[i].next);
   }
}
struct list* get_list_end(struct list* listp) {
   int i;
   for (i = 0; listp[i].next != NULL; listp = listp->next) {}
   printf("list[%d]:%d@%#x->%#x\n",
      i, listp[i].data, &listp[i], listp[i].next);
   return listp;
}

#endif