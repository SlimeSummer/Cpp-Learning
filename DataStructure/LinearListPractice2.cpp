#include <iostream>
#include <vector>

using namespace std;

typedef struct Node {
	int id;
	int password;
	struct Node* next;
} Node;

int main() {
	int n, m;
	vector<int> v;
	cout << "输入人数: ";
	cin >> n;
	cout << "输入起始密码: ";
	cin >> m;

	//将头指针和尾节点指针初始化为空
	Node* head = NULL, * s = NULL;

	//尾插法插入所有人信息
    cout << "依次输入密码: ";
	for (int i = 0; i < n; i++) {
		Node* p = (Node*)malloc(sizeof(Node));
		p -> id = i + 1;
		cin >> p -> password;
		p -> next = NULL;

		if (head == NULL) {
			head = p;
			s = p;
		}
		else {
			s -> next = p;
			s = p;
		}
	}
	s->next = head;  //循环链表

	Node* current = head, * pre = head;

	//循环直到只剩最后一个节点时退出
	while (current -> next != current) {
		//报数
		for (int i = 0; i < m - 1; i++) {
			pre = current;
			current = current -> next;
		}

		//出列节点
		v.push_back(current->id);
		m = current -> password;

		//删除已出列节点
		pre -> next = current -> next;
		free(current);

		current = pre -> next;
	}

	//最后一个节点单独处理
	v.push_back(current -> id);
	free(current);

    cout << "编号序列为：";
    for (auto p = v.begin(); p != v.end(); p++)
        cout << *p << " ";

	return 0;
}