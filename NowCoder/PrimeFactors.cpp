#include <iostream>
#include <vector>

using namespace std;

//质因数分解
vector<int> getPrimeFactors1(int n){   
    vector<int> v;
    while (n%2==0){
        v.push_back(2);
        n/=2;
    }
    for (int i=3; i<=n; i+=2){   //处理大质数时循环次数会很多
        while (n%i==0){
            v.push_back(i);
            n/=i;
        }
    }

    return v;
}

vector<int> getPrimeFactors2(int n){
    vector<int> v;
    while (n%2==0){
        v.push_back(2);
        n/=2;
    }
    for (int i=3; i*i<=n; i+=2){     //处理大质数时能提前跳出，节省操作
        while (n%i==0){
            v.push_back(i);
            n/=i;
        }
    }
    if (n>1)
        v.push_back(n);

    return v;
}

int main(){
    int a;
    cin >> a;
    vector<int> factors=getPrimeFactors2(a);
    
    cout << a << " = ";
    for (size_t i=0; i<factors.size(); i++){
        cout << factors[i];
        if (i<factors.size()-1)
            cout << " * ";
    }
    cout << endl;

    return 0;
}

/*
思考总结：
个人口语版：
在处理奇数因子时，getPrimeFactors1函数的for循环for (int i=3; i<=n; i+=2)在写法上更简洁，但是在处理大质数时会有很多多余的无用循环，
导致时间复杂度上涨（线性阶O(n)），因为如果数n不是质数，则一定可以拆解成两个数相乘的a*b形式，且a<=b, 如果a*a>n，则说明已经不满足拆分的极端边界条件
（因为小于a的奇数在前面的for循环中已经一个一个试了，能拆分的话早就拆分为更小的n了，变成了拆解另一个n的任务。如果a本身的平方还不满足，说明
最后的临界条件已打破）。getPrimeFactors2的for循环则是在这种边界条件下及时作出判断，一旦极端的边界不满足，就认为是质数，只需把这个大于1的
不可拆解数追加到最后即可

更严谨的学术化表达（AI）：
1. 算法描述
算法1（朴素实现）：
for (int i=3; i<=n; i+=2)
该算法在循环条件中采用上限n，对每个奇数因子进行完整遍历。

算法2（优化实现）：
for (int i=3; i*i<=n; i+=2)
该算法将循环上限设置为√n，并在循环结束后处理剩余因子。

2. 时间复杂度分析
定理1：若正整数n为合数，则必存在因子a满足a ≤ √n。
证明：设n = a × b，其中a ≤ b，则a² ≤ a × b = n，因此a ≤ √n。∎
算法1的时间复杂度：在最坏情况下（n为质数），算法需要遍历所有奇数直到n，时间复杂度为O(n)。
算法2的时间复杂度：基于定理1，当遍历至i > √n且未找到因子时，n必为质数。因此最坏情况下的时间复杂度为O(√n)。

3. 算法2的正确性说明
对于任意因子d，若d > √n，则必存在对应因子d′ = n/d < √n
算法遍历所有 ≤ √n 的奇数，确保所有可能的因子对中的较小者被检测
循环结束后，若剩余n > 1，则n必为质数（因其所有小于√n的因子已被排除）

4. 结论
算法2通过数论中的平方根界限原理，将时间复杂度从O(n)优化至O(√n)，在处理大质数时展现出显著的性能优势。
这一优化体现了算法设计中利用数学性质降低计算复杂度的典型思路。
*/