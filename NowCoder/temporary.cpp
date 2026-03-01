#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    long x;
    cin >> n;
    cin >> x;
    int a[n];
    vector<long> record(1,0);

    for (int i=0; i<n; i++)
        cin >> a[i];
    
    int data, max=0, temp=0;
    for (int i=0; i<n; i++){
        data=a[i];
        if (data==x)
            record[0]++;
        else{
            for (int j=1; j<record.size(); j++){
                if (record[j]==data)
                    record[j]++;
                    temp=record[j];
            }
            record.push_back(1);

        }
    }

    if (record[0]>max)
        cout << record[0];
    else
        cout << max-record[0];

    return 0;
}