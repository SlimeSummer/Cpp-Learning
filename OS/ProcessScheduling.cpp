#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef struct Process {
    string name;
    int priority;
    int time;

    //重写排序规则
    bool operator< (const Process& other) const {
        return priority > other.priority;
    }
} Process;

int main() {
    const int N = 3;
    int count = 0;
    vector<Process> pList;
    cout << "请依次输入三个进程的名字,优先级及执行时间!" << endl;

    //输入进程信息
    for (int i = 0; i < N; i++) {
        Process p;
        cin >> p.name >> p.priority >> p.time;
        pList.push_back(p);
    }

    //将所有进程按优先级排序
    sort(pList.begin(), pList.end());

    //执行进程，直到所有队列中所有进程执行完毕
    while (!pList.empty()) {
        //调试用，输出所有进程状态
        // cout << "当前状态" << endl;
        // for (auto p = pList.begin(); p != pList.end(); p++) {
        //     cout << p -> name << " " << p -> priority << " " << p -> time << endl;
        // }

        //取出队列中的第一个进程并执行
        Process p = pList.front();
        pList.erase(pList.begin());
        p.priority -= 1;
        p.time -= 1;
        count += 1;

        //输出执行的进程的信息
        cout << "当前执行次数:" << count << endl;
        cout << "当前正在运行的进程是:" << p.name << endl;

        //判断进程是否执行完成
        if (p.time <= 0) {
            cout << "进程[" << p.name << "]已完成" << endl;
        }
        //如果还未完成，把进程再次放入队列中
        else {
            auto pos = pList.end();  //默认插入到末尾
            for (auto po = pList.begin(); po != pList.end(); po++) {
                if (p.priority > (po -> priority)) {
                    pos = po;
                    break;
                }
            }
            pList.insert(pos, p);
        }
    }

    cout << "所有进程已经完成" << endl;

    return 0;
}