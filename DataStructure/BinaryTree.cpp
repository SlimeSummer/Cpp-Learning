#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

#define MAXSIZE 100
#define OK 1
#define ERROR 0

typedef int Status;
typedef char ElementType;
typedef char String[MAXSIZE];

typedef struct Node {
    ElementType data;
    Node *lchild, *rchild;
}Node, *Tree;

//生成串结构
Status strAssign(String s, char* t) {
    if (strlen(t) > MAXSIZE)
        return ERROR;
    else{
        s[0] = strlen(t);
        for (int i = 1; i <= s[0]; i++)
            s[i] = *(t + i -1);
        return OK;
    }
}

void initTree(Tree& tree) {
    tree = NULL;
}

void createTree(Tree& tree, String s, int& index) {
    ElementType data;
    if (index > s[0])
        return;
    else{
        data = s[index++];

        if (data == '#')
            tree = NULL;
        else {
            tree = (Tree)malloc(sizeof(Node));
            tree -> data = data;
            createTree(tree -> lchild, s, index);
            createTree(tree -> rchild, s, index);
        }
    }
}

void preOrderTraverse(Tree tree, vector<ElementType>& v) {
    if (tree == NULL)
        return;
    else {
        v.push_back(tree -> data);
        preOrderTraverse(tree -> lchild, v);
        preOrderTraverse(tree -> rchild, v);
    }
}

void inOrderTraverse(Tree tree, vector<ElementType>& v) {
    if (tree == NULL)
        return;
    else {
        inOrderTraverse(tree -> lchild, v);
        v.push_back(tree -> data);
        inOrderTraverse(tree -> rchild, v);
    }
}

void postOrderTraverse(Tree tree, vector<ElementType>& v) {
    if (tree == NULL)
        return;
    else {
        postOrderTraverse(tree -> lchild, v);
        postOrderTraverse(tree -> rchild, v);
        v.push_back(tree -> data);
    }
}

void printVector(vector<ElementType> v) {
    for (auto p = v.begin(); p != v.end(); p++)
        cout << *p <<" ";
    cout << endl;
}


int main() {
    String s;
    strAssign(s, "abd##e##cf##g##");
    Tree t;
    initTree(t);

    int index = 1;
    createTree(t, s, index);

    vector<ElementType> v;

    preOrderTraverse(t, v);
    printVector(v);
    v.clear();

    inOrderTraverse(t, v);
    printVector(v);
    v.clear();

    postOrderTraverse(t, v);
    printVector(v);
    v.clear();

    return 0;
}