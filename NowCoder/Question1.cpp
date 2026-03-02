//题目链接：https://ac.nowcoder.com/acm/contest/128678/C

#include<iostream>
#include<cmath>

using namespace std;

bool isPerfectSquare(long long n){
    long long root=sqrt(n);
    return root*root==n;
}

int main(){
    int x,l,r;
    cin >> x >> l >> r;
    for (int y=l; y<=r; y=y++){
        if(isPerfectSquare(x*y)){
            cout << y;
            return 0;
        }
    }

    cout << -1;
    return 0;
}

/*
总结：
1. 判断一个数是否为完全平方数的技巧：先取其平方根，再逆向平方
2. 在main函数使用return语句可提前结束程序
3. 由于for (int y=l; y<=r; y=y++)，时间复杂度为O(n)，因此当l和r相差很大时会有超时的风险，因此最好考虑使用数学的方法解决问题
*/