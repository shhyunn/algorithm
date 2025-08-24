#include <iostream>

using namespace std;
int dp[10001][4];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    dp[1][1] = 1;
    dp[2][1] = dp[2][2] = 1;
    dp[3][1] = dp[3][2] = dp[3][3] = 1;

    for (int i = 4; i < 10001; i++) {
        dp[i][1] = dp[i-1][1];
        dp[i][2] = dp[i-2][1] + dp[i-2][2];
        dp[i][3] = dp[i-3][1] + dp[i-3][2] + dp[i-3][3];
    }

    int N;

    while (T--) {
        cin >> N;
        cout << dp[N][1] + dp[N][2] + dp[N][3] << "\n";
    }

    cout << endl; 
    return 0;
    
}