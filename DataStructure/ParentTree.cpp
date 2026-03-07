#include <iostream>

using namespace std;

#define MAXSIZE 100
#define OK 1
#define ERROR 0

typedef int ElementType;
typedef int Status;

typedef struct Node{
    ElementType data;
    int parent;
}Node;

typedef struct Tree{
    Node nodes[MAXSIZE];
    int root=-1, node=0;
}Tree;

void initTree(Tree& tree){
    tree.root=-1;
    tree.node=0;
}

Status createRoot(Tree& tree, ElementType data){
    if (tree.node>MAXSIZE || tree.root!=-1)
        return ERROR;
    else{
        tree.nodes[0].data=data;
        tree.nodes[0].parent=-1;
        tree.root=0;
        tree.node=1;
        return OK;
    }
}

Status addChildData(Tree& tree, int parent, ElementType data){
    if (tree.node>=MAXSIZE || parent<0 || parent>=tree.node)
        return ERROR;
    else{

        tree.nodes[tree.node].data=data;
        tree.nodes[tree.node].parent=parent;
        tree.node++;
        return OK;
    }
}

// 遍历树（前序遍历风格）
void traverseTree(Tree T, int nodeIndex, int depth) {
    if (nodeIndex == -1 || nodeIndex >= T.node) return;
    
    // 打印当前节点（带缩进表示层级）
    for (int i = 0; i < depth; i++) {
        cout << "  ";
    }
    cout << "|-- " << T.nodes[nodeIndex].data << endl;
    
    // 递归遍历所有子节点
    for (int i = 0; i < T.node; i++) {
        if (T.nodes[i].parent == nodeIndex) {
            traverseTree(T, i, depth + 1);
        }
    }
}

// 打印树的所有信息
void printTree(Tree T) {
    cout << "\n=== Tree Structure ===" << endl;
    if (T.root == -1) {
        cout << "Tree is empty" << endl;
        return;
    }
    cout << "Root node: " << T.nodes[T.root].data << endl;
    cout << "Total nodes: " << T.node << endl;
    
    cout << "\nNode details:" << endl;
    cout << "Index\tData\tParent\tParent Data" << endl;
    for (int i = 0; i < T.node; i++) {
        cout << i << "\t" << T.nodes[i].data << "\t";
        if (T.nodes[i].parent == -1) {
            cout << -1 << "\t(root)";
        } else {
            cout << T.nodes[i].parent << "\t" << T.nodes[T.nodes[i].parent].data;
        }
        cout << endl;
    }
    
    cout << "\nTree Hierarchy:" << endl;
    traverseTree(T, T.root, 0);
}

int main(){
    Tree t;
    createRoot(t, 10);
    addChildData(t, 0, 5);
    addChildData(t, 0, 3);
    addChildData(t, 0, 12);
    addChildData(t, 1, 5);
    addChildData(t, 1, 6);
    printTree(t);

    return 0;
}