#include <iostream>

using namespace std;

#define MAX 100

typedef char ElementType;

typedef struct {
    ElementType data;
    double weight;
    int parent;
    int lchild;
    int rchild;
} Node;

typedef struct {
    Node nodes[MAX];
    int size;
} Tree;

Tree createTree (int size) {
    Tree tree;
    tree.size = size;
    double minL, minR;
    int lnode, rnode;

    cout << "please input data and weight" << endl;

    for (int i = 0; i < 2 * size - 1; i++) {
        if (i < size)
            cin >> tree.nodes[i].data >> tree.nodes[i].weight;
        else
            tree.nodes[i].data = '#';
        tree.nodes[i].parent = -1;
        tree.nodes[i].lchild = -1;
        tree.nodes[i].rchild = -1;
    }

    for (int i = size; i < 2 * size -1; i++) {
        minL = minR = 65536;
        lnode = rnode = -1;

        for (int k = 0; k < i; k++) {
            if (tree.nodes[k].parent == -1) {
                if (tree.nodes[k].weight < minL) {
                    minR = minL;
                    rnode = lnode;
                    minL = tree.nodes[k].weight;
                    lnode = k; 
                }
                else if (tree.nodes[k].weight < minR) {
                    minR = tree.nodes[k].weight;
                    rnode = k;
                }
            }
        }

        tree.nodes[i].weight = minL + minR;
        tree.nodes[i].lchild = lnode;
        tree.nodes[i].rchild = rnode;
        tree.nodes[lnode].parent = i;
        tree.nodes[rnode].parent = i;
    }

    return tree;
}


//打印存储结构中的数据
void printArray(Tree tree) {
    cout << endl << "array:" << endl;
    for (int i = 0; i < tree.size * 2 - 1; i++) {
        cout << tree.nodes[i].data << " " << tree.nodes[i].weight << endl;
    }
}

//以层次图形式打印树, ai生成代码
void printTree(Tree tree) {
    if (tree.size == 0) return;
    
    // 使用数组模拟队列
    int queue[MAX];
    int front = 0, rear = 0;
    int depth[MAX]; // 记录每个节点的深度
    
    // 根节点是最后一个节点
    int root = 2 * tree.size - 2;
    queue[rear++] = root;
    depth[root] = 0;
    
    while (front < rear) {
        int current = queue[front++];
        int currentDepth = depth[current];
        
        // 打印缩进
        for (int i = 0; i < currentDepth; i++) {
            cout << "  ";
        }
        
        // 打印节点
        cout << "|- " << tree.nodes[current].data << " (";
        cout.precision(2);
        cout << fixed << tree.nodes[current].weight << ")" << endl;
        
        // 获取左右子节点
        int left = tree.nodes[current].lchild;
        int right = tree.nodes[current].rchild;
        
        // 按权重从大到小入队子节点
        if (left != -1 && right != -1) {
            if (tree.nodes[left].weight >= tree.nodes[right].weight) {
                queue[rear++] = left;
                depth[left] = currentDepth + 1;
                queue[rear++] = right;
                depth[right] = currentDepth + 1;
            } else {
                queue[rear++] = right;
                depth[right] = currentDepth + 1;
                queue[rear++] = left;
                depth[left] = currentDepth + 1;
            }
        } else if (left != -1) {
            queue[rear++] = left;
            depth[left] = currentDepth + 1;
        } else if (right != -1) {
            queue[rear++] = right;
            depth[right] = currentDepth + 1;
        }
    }
}

int main() {
    Tree tree = createTree(4);
    printArray(tree);
    cout << endl << "Tree structure:" << endl;
    printTree(tree);
    return 0;
}