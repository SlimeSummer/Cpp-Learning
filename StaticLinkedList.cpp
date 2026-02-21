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

int ListLength(StaticLinkList list){
    int length=0;
    int i=list[MAXSIZE-1].cur;
    while (i){
        length++;
        i=list[i].cur;
    }
    return length;
}

int Malloc(StaticLinkList list){
    int i=list[0].cur;
    if (list[0].cur)
        list[0].cur=list[i].cur;
    return i;
}

void Free(StaticLinkList list, int i){
    list[i].cur=list[0].cur;
    list[0].cur=i;
}

Status InitList(StaticLinkList& list){
    for (int i=0; i<MAXSIZE-1; i++)
        list[i].cur=i+1;
    list[MAXSIZE-1].cur=0;
    return OK;
}

Status InsertList(StaticLinkList list, int i, ElementType data){
    if (i<=0 || i>ListLength(list)+1)
        return ERROR;
    else {
        int p=Malloc(list);
        if (p){
            list[p].data=data;
            int k=MAXSIZE-1;
            for (int j=1; j<=i-1; j++)
                k=list[k].cur;
            list[p].cur=list[k].cur;
            list[k].cur=p;
            return OK;
        }
        return ERROR;
    }
}

Status DeleteList(StaticLinkList& list, int i){
    if (i<=0 || i>ListLength(list))
        return ERROR;
    else {
        int k=MAXSIZE-1;
        for (int j=1; j<=i-1; j++)
            k=list[k].cur;
        int p=list[k].cur;
        list[k].cur=list[p].cur;
        Free(list, p);
        return OK;
    }
}

Status GetElement(StaticLinkList list, int i, ElementType& e){
    int j=list[MAXSIZE-1].cur;
    int k=1;
    while (j && k<i){
        j=list[j].cur;
        k++;
    }
    if (!j || k>i)
        return ERROR;
    e=list[j].data;
    return OK;
}

void Traverse(StaticLinkList list){
    int i=1;
    int length=ListLength(list);
    while (i<=length){
        printf("%d >> ",list[i].data);
        i++;
    }
    cout << endl;
}

int main(){
    StaticLinkList l1;
    InitList(l1);
    for (int i=1; i<=10; i++)
        InsertList(l1, i, 2*i);

    InsertList(l1, 1, 1000);
    
    ElementType data;
    
    for (int i=1; i<=ListLength(l1); i++){
        if (GetElement(l1, i, data))
            cout << data << " >> ";
        else
            cout << "ERROR" << " >> ";
    }
    cout << endl;

    return 0;
}