#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<vector<int>> dp;

int main() {
    cin >> N >> K;

    dp.assign(N+1, vector<int>(K+1, 0));

    dp[0][0] = 1;

    for (int i = 0; i < N+1; i++) { //N의 수
        for (int j = 1; j < K+1; j++) { //K개를 이용

            if (i == 0) {
                dp[i][j] = (dp[i][j-1]) % 1000000000;
                
            } else {
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 1000000000;
            }

            
        }
    }

    cout << dp[N][K] << endl;

    return 0;
}