#include <string>
#include <vector>
#define DIVIDED_NUM 1000000007

using namespace std;
//최단 경로의 개수를 -로 나눈 나머지, 물웅덩이는 피해서 가야함
int solution(int m, int n, vector<vector<int>> puddles) {
    
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (auto& p : puddles) {
        dp[p[1] - 1][p[0] - 1] = -1; //물웅덩이
    }
    
    dp[0][0] = 1;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0) continue;
            if (dp[i][j] == -1) {
                dp[i][j] = 0;
                continue;
            }
            
            if (j > 0 && dp[i][j-1] != -1) {
                dp[i][j] = (dp[i][j] + dp[i][j-1]) % DIVIDED_NUM;
            }
            
            if (i > 0 && dp[i-1][j] != -1) {
                dp[i][j] = (dp[i][j] + dp[i-1][j]) % DIVIDED_NUM;
            }
        }
    }
    
    int answer = dp[n-1][m - 1];
    return answer;
}