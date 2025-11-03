#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;


int n;
vector<int> arr;
vector<vector<int>> dp;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    arr.resize(n+2);
    dp.resize(n+2, vector<int>(2, 0));

    for (int i = 0; i < n; i++) {
        cin >> arr[i+2];
    }

    for (int i = 2; i < n+2; i++) {
        dp[i][0] = max(dp[i-2][0], dp[i-2][1]) + arr[i];
        dp[i][1] = dp[i-1][0] + arr[i];
    }

    cout << max(dp[n+1][0], dp[n+1][1]) << endl;


    return 0;
}