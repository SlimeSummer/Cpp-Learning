#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;
#define MAXSIZE 20
#define OK 1
#define ERROR 0

typedef int Status;
typedef int ElementType;
typedef struct Node{
    ElementType data;
    Node* next;
}Node;

typedef struct Node *LinkList;

Status GetElement(LinkList list, int i, ElementType& e){
    LinkList p;
    p=list->next;
    int j=1;
    while (p && j<i){
        p=p->next;
        j++;
    }
    if (!p || j>i)
        return ERROR;
    e=p->data;
    return OK;
}

Status InsertList(LinkList list, int i, ElementType e){
    LinkList p;
    p=list;
    int j=1;
    while (p && j<i){
        p=p->next;
        j++;
    }
    if (!p || j>i)
        return ERROR;
    LinkList s=(LinkList)malloc(sizeof(Node));
    s->data=e;
    s->next=p->next;
    p->next=s;
    list->data++;
    return OK;
}

Status DeleteList(LinkList list, int i, ElementType e){
    LinkList p=list;
    int j=1;
    while (p->next && j<i){
        p=p->next;
        j++;
    }
    if (!(p->next) || j>i)
        return ERROR;
    LinkList q=p->next;
    p->next=q->next;
    e=q->data;
    free(q);
    list->data--;
    return OK;
}

void CreateList(LinkList& list, int n){
    list=(LinkList)malloc(sizeof(Node));
    LinkList r=list;
    LinkList p;
    for (int i=1; i<=n; i++){
        p=(LinkList)malloc(sizeof(Node));
        p->data=2*i;
        r->next=p;
        r=p;
    }
    r->next=NULL;
    list->data=n;
}

Status ClearList(LinkList list){
    LinkList p,q;
    p=list->next;
    while(p){
        q=p->next;
        free(p);
        p=q;
    }
    list=NULL;
    return OK;
}

int main(){
    LinkList l1;
    CreateList(l1, 10);

    InsertList(l1, 1, 100);
    InsertList(l1, 4, 100);

    int i=1;
    ElementType e;
    while (i<=l1->data){
        GetElement(l1, i, e);
        cout << e << endl;
        i++;
    }
    return 0;
}


