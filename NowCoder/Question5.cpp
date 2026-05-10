//题目：https://ac.nowcoder.com/acm/contest/134527/E

#include <iostream>
#include <stack>

using namespace std;

void printResult(int seq[], int n) {
    for (int i = 0; i < n; i++) {
        int pos = i + 1;
        int a = seq[i];

        //子序列全部数量
        int totalSeq = pos * (n - pos + 1);

        //初始化左右两边的边界墙
        int left = 0;
        int right = n + 1;

        //找左边界墙
        for (int j = i - 1; j >= 0; j--) {
            if (seq[j] > seq[i]) {
                left = j + 1;
                break;
            }
        }

        //找右边界墙
        for (int j = i + 1; j < n; j++) {
            if (seq[j] > seq[i]) {
                right = j + 1;
                break;
            }
        }

        //不可见序列数量
        long long invisibleSeq = (long long)left * (n - right + 1);

        //计算可见子区间数
        long long result = totalSeq - (long long)invisibleSeq;

        cout << result << " ";
    }
}

void printResult2(int seq[], int n) {
    stack<int> stk;

    //存序列中每个元素的左边界
    int* leftArr = new int[n];
    //存序列中每个元素的右边界
    int* rightArr = new int[n];
    
    //找每个元素的左边界并存放
    for (int i = 0; i < n; i++) {
        while (!stk.empty() && seq[stk.top()] <= seq[i]) {
            stk.pop();
        }

        if (stk.empty()){
            leftArr[i] = 0;
        }
        else{
            leftArr[i] = stk.top() + 1;
        }

        stk.push(i);
    }
    
    // 弹出全部元素清空栈
    while (!stk.empty())
        stk.pop();
    
    //找每个元素的右边界并存放
    for (int i = n - 1; i >= 0; i--) {
        while (!stk.empty() && seq[stk.top()] <= seq[i]) {
            stk.pop();
        }

        if (stk.empty())
            rightArr[i] = n + 1;
        else
            rightArr[i] = stk.top() + 1;

        stk.push(i);
    }

    //统一计算原序列每个元素的可见子区间数
    for (int i = 0; i < n; i++) {
        int pos = i + 1;

        //子序列全部数量
        long long totalSeq = (long long)pos * (n - pos + 1);

        //不可见序列数量
        long long invisibleSeq = (long long)leftArr[i] * (n - rightArr[i] + 1);

        //计算可见子区间数
        long long result = totalSeq - invisibleSeq;

        cout << result << " ";
    }
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int n;
        cin >> n;
        int seq[n];

        for (int j = 0; j < n; j++) {
            cin >> seq[j]; 
        }

        //传统方法，时间复杂度大
        //printResult(seq, n);

        //原有基础上通过栈优化时间复杂度的方法
        printResult2(seq, n);
        
        cout << endl;
    }

    return 0;
}

/*
总结：
1. 用x表示pi在排列p中的位置（注意不是数组下标，是表示第几个位置），那么在原序列中，包含第x的元素的全部子区间个数为：U = x * (n - x + 1)。其中x代表子区间左
端点的取值范围是从0,1,2，……，x，共x个；(n-x+1)表示区间右端点的取值范围是x, x+1, x+2,……，n, 共(n-x+1)个（n减去x后还要加1是因为还要把x算进去，否则会漏掉）。
那么总共的选择数量就是两者相乘（区间就是左右端点选择的组合情况，相乘就是组合原理），在得出所有的子区间数目后，下一步就是把不符合要求的区间排除出去，剩下的就是
符合要求的“可见子区间数量”
    反思：这反映了一种做事的哲学原则：如果要找某个符合条件的事物，那么可以用集合的方法先列举出全部事物，然后再找出不符合条件的事物并排除出去，剩下的补集就是
符条件的事物。是一种通过集合建模间接解决问题的方法论思想

2. 要想找出不符合要求的区间，就要找出第x的元素两旁的“边界墙”在哪里（即左右两边越过这个“墙”就会被挡住的具体位置），例如：12,1,3,6,10中，如果第x元素代表6，那么
它的“左边界墙”就是12（12比6大，把6挡住了，再往左走就不符合要求，变成不可见区间），同理，它的“右边界墙”就是10。设两个集合：A：左边界墙往左走不符合要求的区间数
（即被“左边界墙”截断的左端点区间）；B：右边界墙往右走不符合要求的区间数（即被“右边界墙”截断的右端点区间） （其实严谨的表述为：A：在子区间内，x的左边存在一个元素
大于当前x的元素的区间集合。B：在子区间内，x 的右边存在一个元素大于当前x的元素的区间集合）。那么反过来，“左边可见” = 左边没有比它大的数  = 不在集合A中
= 集合A的补集CuA，即“左边可见”逻辑等价于“集合A的补集CuA”；同理，“右边可见” = 右边没有比它大的数  = 不在集合B中 = 集合B的补集CuB，即“右边可见”逻辑等价于“集合B
的补集CuB” （注意，全集U就是之前求出的U = x * (n - x + 1)，即包含第x的元素的全部子区间个数）。那么，符合要求的“可见区间”就是 CuA ∪ CuB，即“左边可见” 和
“右边可见”的并集，下一步就是把这个并集CuA ∪ CuB找出来

3. 根据容斥原理，可以知道|CuA ∪ CuB| = |U| - |A ∩ B| （画集合图就可以推出这个公式），只要知道|A ∩ B|，就可以得出符合要求的“可见区间了”。这里的|A ∩ B|表示
集合A和集合B的交集的个数 = “左边和右边同时不可见”的区间个数 = “左边界墙”往左选择的个数 * “右边界墙”往右选择的个数 （即不符合要求的左端点个数 * 不符合要求的
右端点个数），如何理解这里的相乘？两者相乘就是求左右搭配的组合情况个数，计数原理。
    例如：2 8 5 4 7 12 1 3 6 10 9 11中，如果x=5，代表现在处理元素“7”（数组下标是4）的可见子区间个数，从7出发往左走，发现到8就被“挡住了”，再往左走就是“左不可
见”，因此左边界墙的位置就是2（第2个数）；从7出发往右走，发现到12就被“挡住了”，再往右走就是“右不可见”，因此右边界墙的位置就是6（第6个数）。那么即不符合要求的
左端点个数就是2，符合要求的右端点个数是7，|A ∩ B| = 2 * 7 = 14。那么符合条件的区间数|CuA ∪ CuB|为|U| - |A ∩ B| = 40 - 14 = 26个

4. 在第二个优化后的方法中，先提前把原序列的每个左右边界墙位置找出来，再统一计算。找的过程中使用栈来动态地记录每个位置的左右墙在哪里，边找边及时地淘汰掉前面已
无实际价值的“高点”，动态地更新“边界墙”的位置。而不是每次给每个元素找边界墙时，都从头到尾重复找。

*/