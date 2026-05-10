#include <iostream>

using namespace std;

#define MAXSIZE 20
#define OK 1
#define ERROR 0

typedef int ElementType;
typedef int Status;

typedef struct SqList {
    ElementType data[MAXSIZE];
    int length;
}*List;

void initialList(List& list) {
    list = (List)malloc(sizeof(SqList));
    list -> length = 0;
}

void CreateList(List& list, ElementType arr[], int n) {
    list = (List)malloc(sizeof(SqList));
    for (int i = 0; i < n; i++)
        list -> data[i] = arr[i];
    list -> length = n;
}

Status addElement(List list, int pos, ElementType e) {
    if ((list -> length) >= MAXSIZE || pos <=0 || pos > (list -> length + 1))
        return ERROR;
    else{
        for (int i = list -> length; i >= pos; i--)
            list -> data[i] = list -> data[i-1];
        list -> data[pos-1] = e;
        list -> length++;
        return OK;
    }
}

Status delElement(List list, int pos) {
    if (pos <=0 || pos > (list -> length))
        return ERROR;
    else{
        for (int i = pos; i < list -> length; i++)
            list -> data[i-1] = list -> data[i];
        list -> length--;
        return OK;
    }
}

int locateElement(List list, ElementType e) {
    for (int i = 0; i < list -> length; i++){
        if (list -> data[i] == e)
            return i + 1;
    }
    return -1;
}

Status getElement(List list, int pos, ElementType &e) {
    if (pos <= 0 || pos > (list -> length))
        return ERROR;
    else
        return list -> data[pos-1];
}

bool listEmpty(List list) {
    return (list -> length == 0);
}

int listLength(List list) {
    return list -> length; 
}

void printList(List list) {
    for (int i = 0; i < list -> length; i++)
        cout << list -> data[i] <<" ";
    cout << endl;
}

void DestroyList(List list) {
    free(list);
}


int main() {
    ElementType arr[4] = {3, 1, 4, 7};
    List l;
    CreateList(l, arr, 4);

    addElement(l, 1, 8);
    addElement(l, 6, 2);
    addElement(l, 2, 9);
    delElement(l, 4);

    printList(l);

    cout << locateElement(l, 2) << endl;

    initialList(l);
    addElement(l, 1, 3);
    DestroyList(l);
    printList(l);
    return 0;
}