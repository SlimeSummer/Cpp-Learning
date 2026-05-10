#include <iostream>
#include <vector>

using namespace std;

int main() {
    long N, K;
    cin >> N >> K;

    vector<vector<int>> arr(N);

    for (int i = 0; i < N; i++) {
        int l;
        cin >> l;
        arr[i].resize(l);

        for (int j = 0; j < l; j++) {
            cin >> arr[i][j];
        }
    }

    vector<int> b;
    int count = 1;
    for (int i = 0; i < N; i++) {
        int c;
        cin >> c;

        long bound = arr[i].size() * c;

        if (K > bound) {
            K = K - bound;
        }
        else {
            int pos = (K-1) % arr[i].size();
            cout << arr[i][pos];
            break;
        }
    }

    return 0;
}
