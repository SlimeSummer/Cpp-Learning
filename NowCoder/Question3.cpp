//题目链接: https://www.xfxcy.com/p/X1019?tid=692465affdd1a52d3130a5cc

#include <iostream>
#include <algorithm>

using namespace std;

typedef struct student{
    int a, b, c, total, id;
}student;

typedef struct student2{
    int a, b, c, total, id;

    bool operator< (const student2& s2) const{
        if (total!=s2.total) return total>s2.total;
        if (a != s2.a) return a > s2.a;
        if (b != s2.b) return b > s2.b;
        if (c != s2.c) return c > s2.c;
        return id < s2.id;
    }
}student2;

bool customCompare(const student& s1, const student& s2){
    if (s1.total!=s2.total) return s1.total>s2.total;
    if (s1.a != s2.a) return s1.a > s2.a;
    if (s1.b != s2.b) return s1.b > s2.b;
    if (s1.c != s2.c) return s1.c > s2.c;
    return s1.id < s2.id;
}

void method1(){
    int n;
    cin >> n;
    student s[n];
    for(int i=0; i<n ;i++){
        int a,b,c;
        cin >> a >> b >> c;
        s[i]={a, b, c, a+b+c, i+1};
    }

    sort(s, s+n, customCompare);

    for (int i=0; i<n ; i++)
        cout << s[i].id << ' ' << s[i].total << ' ' << s[i].a <<
         ' ' << s[i].b << ' ' << s[i].c << endl;
}

void method2(){
    int n;
    cin >> n;
    student s[n];
    for(int i=0; i<n ;i++){
        int a,b,c;
        cin >> a >> b >> c;
        s[i]={a, b, c, a+b+c, i+1};
    }

    sort(s, s+n);

    for (int i=0; i<n ; i++)
        cout << s[i].id << ' ' << s[i].total << ' ' << s[i].a <<
         ' ' << s[i].b << ' ' << s[i].c << endl;
}

int main(){
    method2();
    
    return 0;
}

/*
总结：
C++默认使用“<”运算符作为比较标准，判断规则为：a < b 表示a应该排在b前面。那么当重载了结构体的<符号时，相当于重载了结构体的排序规则，
重载<运算符的本质是：当一个对象小于另一个时，实际意味着什么。
*/