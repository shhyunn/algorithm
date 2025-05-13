#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long dp[1 << 10][101][10];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    if (n <= 9) {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 1; i <= 9; i++) {
        dp[1<<i][1][i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int k = 0; k < 10; k++) {
            for (int bit = 0; bit < (1 << 10); bit++) {
                if (k == 0) {
                    dp[bit | (1 << k)][i][k] += dp[bit][i-1][k+1] % (int)10e8;
                }

                else if (k == 9) {
                    dp[bit | (1 << k)][i][k] += dp[bit][i-1][k-1] % (int)10e8;
                }
                else {
                    dp[bit | (1 << k)][i][k] += (dp[bit][i-1][k-1] + dp[bit][i-1][k+1]) % (int)10e8;
                }
            }
        }
    }

    long long answer = 0;

    for (int i = 0; i < 10; i++) {
        answer = ( answer + dp[(1 << 10) - 1][n][i] ) % (int)10e8;
    }

    cout << answer << endl;
    
    
    return 0;
}