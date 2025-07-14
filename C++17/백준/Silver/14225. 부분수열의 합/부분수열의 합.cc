#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N; int cnt;
vector<int> arr;
int res[2000001] = {0,};

void func(int id, int sums) {
    if (id == N) {
        res[sums] = 1;
        return;
    };
    func(id + 1, sums + arr[id]);
    func(id + 1, sums);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    arr.resize(N);

    for (int i =0; i < N; i++) {
        cin >> arr[i];
    }
    int index = 0;
    
    func(0, 0);

    for (int i = 1; i < 2000001; i++) {
        if (res[i] == 0) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}