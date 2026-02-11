#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, K;
vector<int> arr;
vector<int> diffs;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    arr.assign(N, 0);
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < N-1; i++) {
        diffs.push_back(abs(arr[i+1] - arr[i]));
    }

    sort(diffs.begin(), diffs.end());

    int cnt = 0;
    
    while (!diffs.empty() && cnt < K-1) {
        diffs.pop_back();
        cnt++;
    }

    int answer = 0;
    for (int i = 0; i < diffs.size(); i++) {
        answer += diffs[i];
    }

    cout << answer << endl;

   
    return 0;
}