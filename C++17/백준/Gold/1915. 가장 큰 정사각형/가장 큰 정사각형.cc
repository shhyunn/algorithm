#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;
vector<vector<int>> arr;
vector<vector<int>> dp;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    arr.assign(N, vector<int>(M, 0));
    dp.assign(N, vector<int>(M, 0));

    string ss;

    for (int i = 0; i < N; i++) {
        cin >> ss;
        for (int j = 0; j < ss.size(); j++) {
            arr[i][j] = ss[j] - '0';
        }
    }

    int answer = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == 0) continue;

            if (i == 0 || j == 0) {
                dp[i][j] = 1;

            } else {
                if (arr[i-1][j] == 1 && arr[i][j-1] == 1 && arr[i-1][j-1] == 1) {
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                } else {
                    dp[i][j] = 1;
                }
            }
            answer = max(dp[i][j], answer);
        }
    }

    cout << answer * answer << endl;


    return 0;
}