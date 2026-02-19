#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<vector<pair<int, int>>> arr;
vector<int> dp;
vector<int> prefMax;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    int t, p;
    arr.assign(N + 1, vector<pair<int,int>>());
    dp.assign(N+1, 0);
    prefMax.assign(N + 1, 0);

    for (int i = 1; i < N+1; i++) {
        cin >> t >> p;
        if (i + t - 1 > N) continue;
        arr[i+t-1].push_back({t, p});
    }

   
    for (int i = 1; i < N+1; i++) {
        for (auto& t : arr[i]) {
            int startDay = i - t.first + 1;
            dp[i] = max(dp[i], prefMax[startDay - 1] + t.second);
           
        }
        prefMax[i] = max(prefMax[i-1], dp[i]);
    }

    int max_value = 0;

    for (int i = 0; i < N+1; i++) {
        max_value = max(max_value, dp[i]);
    }

    cout << max_value << endl;

    return 0;
}