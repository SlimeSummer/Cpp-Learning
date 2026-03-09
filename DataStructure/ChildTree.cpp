#include <iostream>

using namespace std;

#define MAXSIZE 100
#define OK 1
#define ERROR 0

typedef int Status;
typedef int ElementType;

typedef struct ChildNode {
    int child;
    ChildNode* next;
} ChildNode;

typedef struct DataNode {
    ElementType data;
    ChildNode* firstchild;
} DataNode;

typedef struct ChildTree {
    DataNode nodes[MAXSIZE];
    int root, node;
} Tree;

void initTree(Tree& tree) {
    tree.root = -1;
    tree.node = 0;
    for (int i = 0; i < MAXSIZE; i++) 
        tree.nodes[i].firstchild = NULL;
}

Status createRoot(Tree& tree, ElementType data) {
    if (tree.root != -1 || tree.node > MAXSIZE)
        return ERROR;
    else{
        tree.nodes[0].data = data;
        tree.node = 1;
        tree.root = 0;
        return OK;
    }
}

Status addChildData(Tree& tree, int parent, ElementType data) {
    if (tree.node >= MAXSIZE || parent < 0 || parent >= tree.node)
        return ERROR;
    else{
        tree.nodes[tree.node].data = data;
        ChildNode* cnode = (ChildNode*)malloc(sizeof(ChildNode));
        cnode -> child = tree.node++;
        cnode -> next = NULL;

        if (tree.nodes[parent].firstchild == NULL)
            tree.nodes[parent].firstchild = cnode;
        else {
            ChildNode* p = tree.nodes[parent].firstchild;
            while (p -> next != NULL) 
                p = p -> next;
            p -> next = cnode;
        }
        
        return OK;
    }
}

// 递归遍历树（孩子表示法）
void traverseTree(Tree T, int nodeIndex, int depth) {
    if (nodeIndex == -1 || nodeIndex >= T.node) return;
    
    // 打印当前节点（带缩进表示层级）
    for (int i = 0; i < depth; i++) {
        cout << "  ";
    }
    cout << "|-- " << T.nodes[nodeIndex].data << endl;
    
    // 遍历当前节点的所有孩子节点
    ChildNode* child = T.nodes[nodeIndex].firstchild;
    while (child != NULL) {
        traverseTree(T, child->child, depth + 1);
        child = child->next;
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
    
    cout << "\nNode details (Child List):" << endl;
    cout << "Index\tData\tChildren" << endl;
    
    for (int i = 0; i < T.node; i++) {
        cout << i << "\t" << T.nodes[i].data << "\t";
        
        ChildNode* child = T.nodes[i].firstchild;
        if (child == NULL) {
            cout << "(leaf)";
        } else {
            cout << "[";
            while (child != NULL) {
                cout << child->child;
                if (child->next != NULL) cout << ", ";
                child = child->next;
            }
            cout << "]";
        }
        cout << endl;
    }
    
    cout << "\nTree Hierarchy:" << endl;
    traverseTree(T, T.root, 0);
}

// 计算并打印树的度、高度等统计信息
void printTreeStats(Tree T) {
    if (T.root == -1) {
        cout << "Tree is empty" << endl;
        return;
    }
    
    cout << "\n=== Tree Statistics ===" << endl;
    
    // 计算树的度（最大孩子数）
    int maxDegree = 0;
    for (int i = 0; i < T.node; i++) {
        int degree = 0;
        ChildNode* child = T.nodes[i].firstchild;
        while (child != NULL) {
            degree++;
            child = child->next;
        }
        if (degree > maxDegree) maxDegree = degree;
    }
    cout << "Tree degree: " << maxDegree << endl;
    
    // 计算叶子节点数
    int leafCount = 0;
    for (int i = 0; i < T.node; i++) {
        if (T.nodes[i].firstchild == NULL) leafCount++;
    }
    cout << "Leaf nodes: " << leafCount << endl;
    
    // 计算非叶子节点数
    cout << "Internal nodes: " << T.node - leafCount << endl;
}

int main() {
    Tree t;

    initTree(t);
    createRoot(t, 5);
    addChildData(t, 0, 10);
    addChildData(t, 0, 9);
    addChildData(t, 0, 12);
    addChildData(t, 1, 4);
    addChildData(t, 1, 6);

    printTree(t);

    return 0;
}