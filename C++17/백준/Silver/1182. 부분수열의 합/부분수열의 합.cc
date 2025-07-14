#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N; int S; int cnt;
vector<int> arr;

void func(int id, int sums, int k) {
    if (id == N) {
        if (k > 0 && S == sums) cnt++;
        return;
    };
    func(id + 1, sums + arr[id], k+1);
    func(id + 1, sums, k);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> S;
    arr.resize(N);

    for (int i =0; i < N; i++) {
        cin >> arr[i];
    }
    int index = 0;
    
    func(0, 0, 0);
    cout << cnt << endl;

    
    return 0;
}