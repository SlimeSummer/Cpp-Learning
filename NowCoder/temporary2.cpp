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