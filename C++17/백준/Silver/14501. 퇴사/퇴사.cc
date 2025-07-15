#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector<pair<int, int>> arr;
int res;

void func(int id, int val) {
    if (id == N) {
        res = max(val, res);
        return;
    }

    int p = arr[id].first;
    int s = arr[id].second;

    if (id + p <= N) {
        func(id + p, val + s);
    }
    func(id + 1, val);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    arr.resize(N, {0,0});

    for (int i = 0; i < N; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    func(0,0);
    cout << res << endl;
    return 0;
}