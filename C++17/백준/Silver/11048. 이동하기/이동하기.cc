#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;
vector<vector<int> > maps;
vector<vector<int> > dp;
//r+1, c
//r, c+1
//r+1, c+1

int main() {
    cin >> N >> M;
    maps.resize(N, vector<int>(M, 0));
    dp.resize(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> maps[i][j];
        }
    }
    int tmp = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i > 0) dp[i][j] = max(dp[i][j], dp[i-1][j]);
            if (j > 0) dp[i][j] = max(dp[i][j], dp[i][j-1]);
            if (i > 0 && j > 0) dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
            dp[i][j] += maps[i][j];
        }
    }

    cout << dp[N-1][M-1];

    return 0;
}