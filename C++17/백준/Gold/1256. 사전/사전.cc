#include <iostream>
#include <string>
using namespace std;

int dp[101][101];

int main() {
    int N; int M; int K;
    cin >> N >> M >> K;

    for (int i = 1; i < 101; i++) {
        dp[i][0] = dp[0][i] = 1; 
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1]; // 개수 저장
            if (dp[i][j] > 1000000000) dp[i][j] = 1000000000;
        }
    }

    if (dp[N][M] < K) {
        cout << -1;
        return 0;
    }

    int a_cnt = N;
    int z_cnt = M;

    for (int i = 0; i < N + M; i++) {
        int as = dp[a_cnt-1][z_cnt];

        if (a_cnt == 0) {
            cout << 'z';
            z_cnt--;
        }

        else if (z_cnt == 0) {
            cout << 'a';
            a_cnt--;
        }

        else if (K <= as) {
            cout << 'a';
            a_cnt--;
        } 
        
        else {
            cout << 'z';
            K -= as;
            z_cnt--;
        }
    }
    return 0;
}