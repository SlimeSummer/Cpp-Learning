#include <iostream>

using namespace std;

#define MAXSIZE 100
#define OK 1
#define ERROR 0

typedef int ElementType;
typedef int Status;

typedef struct Node{
    ElementType data;
    Node* firstchild, *rightsib;
}Node;

typedef struct ChildrenSibTree{
    Node nodes[MAXSIZE];
    int root, node;
}Tree;

void initTree(Tree& tree) {
    tree.root = -1;
    tree.node = 0;
}

Status createRoot(Tree& tree, ElementType data) {
    if (tree.root != -1 || tree.node > MAXSIZE)
        return ERROR;
    else{
        tree.nodes[0].data = data;
        tree.nodes[0].firstchild = NULL;
        tree.nodes[0].rightsib = NULL;
        tree.node = 1;
        tree.root = 0;
        return OK;
    }
}

Status addChild(Tree& tree, int parent, ElementType data) {
    if (tree.node >= MAXSIZE ||  parent < 0 || parent >= tree.node)
        return ERROR;
    else {
        Node* newNode = &tree.nodes[tree.node];
        newNode -> data = data;
        newNode -> firstchild = NULL;
        newNode -> rightsib = NULL;
        tree.node++;

        if (tree.nodes[parent].firstchild == NULL)
            tree.nodes[parent].firstchild = newNode;
        else{
            Node *p = tree.nodes[parent].firstchild;
            while (p -> rightsib != NULL)
                p = p->rightsib;
            p -> rightsib = newNode;
        }
        return OK;
    }
}

// 添加打印函数
void printNode(Node* node, int depth) {
    if (node == NULL) return;
    
    // 打印当前节点
    for (int i = 0; i < depth; i++) {
        cout << "  ";
    }
    cout << "|-- " << node->data << endl;
    
    // 递归打印第一个子节点
    if (node->firstchild != NULL) {
        printNode(node->firstchild, depth + 1);
    }
    
    // 递归打印右兄弟节点
    if (node->rightsib != NULL) {
        printNode(node->rightsib, depth);
    }
}

void printTree(Tree& tree) {
    cout << "\n=== Tree Structure ===" << endl;
    
    if (tree.root == -1) {
        cout << "Tree is empty" << endl;
        return;
    }
    
    cout << "Root index: " << tree.root << endl;
    cout << "Root data: " << tree.nodes[tree.root].data << endl;
    cout << "Total nodes: " << tree.node << endl;
    
    cout << "\nNode details:" << endl;
    cout << "Index\tData" << endl;
    for (int i = 0; i < tree.node; i++) {
        cout << i << "\t" << tree.nodes[i].data << endl;
    }
    
    cout << "\nTree Hierarchy:" << endl;
    printNode(&tree.nodes[tree.root], 0);
}


int main(){
    Tree t;

    initTree(t);
    createRoot(t, 5);
    addChild(t, 0, 10);
    addChild(t, 0, 9);
    addChild(t, 0, 12);
    addChild(t, 1, 4);
    addChild(t, 1, 6);

    printTree(t);

    return 0;
}