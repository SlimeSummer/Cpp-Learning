//题目链接：https://ac.nowcoder.com/acm/contest/128678/B

#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    unordered_map<int, int> umap;

    for (int i=0, v; i<n; i++)
        cin >> v, umap[v]++;
    int mx=0;
    for (auto [_,val] : umap)
        mx=max(val, mx);
    cout << mx-umap[x] <<endl;
    
    return 0;
}

/*
总结：
1. for (auto [_,val] : umap)是c++17的结构化绑定用法，其中的中括号[ , ]用于绑定变量,"[_, val]"中的"_"表示不关心key值。c++11的基于范围的
for循环写法为：for (auto& pair : mp) {mx = max(mx, pair.second);}，更早的迭代器写法为：for (auto it = mp.begin(); it != mp.end(); ++it) 
{mx = max(mx, it->second);}，对于只读访问而言，更规范的写法是加上const，即为for (const auto& pair : mp)
*/

