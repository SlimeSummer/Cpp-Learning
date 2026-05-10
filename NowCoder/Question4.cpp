//题目：https://ac.nowcoder.com/acm/contest/134527/C
#include <bits/stdc++.h>

using namespace std;

int main() {
    long T, L, R;
    cin >> T;

    for (long i = 0; i < T; i++) {
        cin >> L >> R;
        int count = 0;

        for (int w = L; w <= R; w++) {
            int coun = 0;

            for (long b = 0; b < 64; b++) {
                long long test = (1LL << b);
                if (w & (test)) {
                    coun++;
                }
            }

            if (coun == 2 || (coun == 1 && w >= 2)) {
                count++;
            }
        }

        cout << count << endl;
    }

    return 0;
}