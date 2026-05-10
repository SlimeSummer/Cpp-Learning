#include <iostream>
#include <vector>

using namespace std;

#define MAXSIZE 100

typedef struct {
    int id;
    int password;
} Person;

int main() {
    int n, m;
    cout << "输入人数：";
    cin >> n;
    cout << "输入起始密码：";
    cin >> m;

    Person person[MAXSIZE];
    vector<int> v;

    cout << "依次输入每个人的密码：" << endl;
    for (int i = 0; i < n; i++) {
        person[i].id = i + 1;
        cin >> person[i].password;
    }

    bool readable[n];
    for (int i = 0; i < n; i++)
        readable[i] = true;

    int read = 0, count = 0, index = 0;

    //循环直到所有人出列
    while (read < n) {   
        if (readable[index] == true) {
            count++;   //该位置报数
            if (count == m) {
                v.push_back(person[index].id);  //把出列的人的id放进列表中
                m = person[index].password;
                read++;  //出列人数+1
                readable[index] = false; //当前位置标记为不可访问
                count = 0; //重新报数
            }
        }

        index = (index + 1) % n;
    }

    //输出整个列表
    cout << "编号序列为：";
    for (auto p = v.begin(); p!=v.end(); p++)  
        cout << *p << " ";

    return 0;
}