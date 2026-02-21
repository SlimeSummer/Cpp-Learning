#include<iostream>

using namespace std;
#define MAXSIZE 1000
#define OK 1
#define ERROR 0

typedef int ElementType;
typedef int Status;
typedef struct{
    ElementType data;
    int cur;
}StaticLinkList[MAXSIZE];

Status InitList(StaticLinkList& list){
    for (int i=0; i<MAXSIZE-1; i++)
        list[i].cur=i+1;
    list[MAXSIZE-1].cur=0;
    return OK;
}