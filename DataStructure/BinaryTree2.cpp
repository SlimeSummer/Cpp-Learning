#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define STACKSIZE 20
#define LEFT 0
#define RIGHT 1

typedef char ElementType;
typedef int ChildType;

typedef struct Node {
    ElementType data;
    Node *lchild, *rchild;
} Node, *BiTree;

//创建树
BiTree CreateBiTree(string s) {
    //树的根结点初始化为空
    BiTree tree = NULL;
    //定义栈用于储存结点操作状态
    Node *stack[STACKSIZE], *p;
    //栈顶指针、结点类型初始化
    int top = -1, ChildType = LEFT;

    //对传入的字符串进行逐个处理
    for (int i = 0; i < s.length(); i++) {
        switch (s[i]) {
        //将结点入栈作为父结点
        case '(':
            top++;
            stack[top] = p;
            ChildType = LEFT;
            break;
        //父结点的分支处理完毕，出栈
        case ')':
            top--;
            break;
        //左分支处理完毕，切换为右分支
        case ',':
            ChildType = RIGHT;
            break;
        default:
            //生成新的结点并存入数据
            p = (Node*)malloc(sizeof(Node));
            p -> data = s[i];
            p -> lchild = p -> rchild = NULL;

            //树无根结点时作为根结点
            if (tree == NULL)
                tree = p;
            //有根结点时根据情况和栈顶父结点建立联系
            else {
                switch (ChildType) {
                    case LEFT:
                        stack[top] -> lchild = p;
                        break;
                    case RIGHT:
                        stack[top] -> rchild = p;
                        break;
                }
            }
        }
    }
    return tree;
}

//统计叶子节点个数
void CountLeafNode (BiTree tree, int& counter) {
    if (tree == NULL)
        return;
    else{
        //判断叶子节点
        if (tree -> lchild == NULL && tree -> rchild == NULL)
            counter++;
        CountLeafNode(tree -> lchild, counter);
        CountLeafNode(tree -> rchild, counter);
    }
}

void SwapLR (BiTree tree) {
    if (tree == NULL)
        return;
    else {
        SwapLR(tree -> lchild);
        SwapLR(tree -> rchild);
        //交换左右子树
        BiTree temp;
        temp = tree -> lchild;
        tree -> lchild = tree -> rchild;
        tree -> rchild = temp; 
        
    }
}

void PreOrderTraverse(BiTree tree, vector<ElementType>& v) {
    if (tree == NULL)
        return;
    else {
        v.push_back(tree -> data);
        PreOrderTraverse(tree -> lchild, v);
        PreOrderTraverse(tree -> rchild, v);
    }
}

void InOrderTraverse(BiTree tree, vector<ElementType>& v) {
    if (tree == NULL)
        return;
    else {
        InOrderTraverse(tree -> lchild, v);
        v.push_back(tree -> data);
        InOrderTraverse(tree -> rchild, v);
    }
}

void PostOrderTraverse(BiTree tree, vector<ElementType>& v) {
    if (tree == NULL)
        return;
    else {
        PostOrderTraverse(tree -> lchild, v);
        PostOrderTraverse(tree -> rchild, v);
        v.push_back(tree -> data);
    }
}

void PrintVector(const vector<ElementType>& v) {
    for (auto p = v.begin(); p != v.end(); p++)
        cout << *p << " ";
    cout << endl;
}

int main() {
    vector<ElementType> v;
    BiTree tree = CreateBiTree("A(B(D(,G)),C(E,F))");
    //BiTree tree = CreateBiTree("A(B(D,E),C)");

    cout << "前序遍历" << endl;
    PreOrderTraverse(tree, v);
    PrintVector(v);
    v.clear();

    cout << "中序遍历" << endl;
    InOrderTraverse(tree, v);
    PrintVector(v);
    v.clear();

    cout << "后序遍历" << endl;
    PostOrderTraverse(tree, v);
    PrintVector(v);
    v.clear();

    int count = 0;
    CountLeafNode(tree, count);
    cout << "叶子节点个数：" << count << endl;

    cout << "交换左右子树后：" << endl;
    SwapLR(tree);

    cout << "前序遍历" << endl;
    PreOrderTraverse(tree, v);
    PrintVector(v);
    v.clear();

    cout << "中序遍历" << endl;
    InOrderTraverse(tree, v);
    PrintVector(v);
    v.clear();

    return 0;
}