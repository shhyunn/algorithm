#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, K;
vector<long long> arr;
vector<long long> diffs;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    arr.assign(N, 0);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < N-1; i++) {
        diffs.push_back(arr[i+1] - arr[i]);
    }

    sort(diffs.begin(), diffs.end());

    for (int i = 0; i < K - 1; i++) {
        diffs.pop_back();
    }

    long long answer = 0;
    for (int i = 0; i < diffs.size(); i++) {
        answer += diffs[i];
    }

    cout << answer << endl;
   
    return 0;
}