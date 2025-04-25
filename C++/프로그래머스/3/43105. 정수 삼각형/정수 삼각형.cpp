#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    
    int size = triangle.size();
    vector<vector<int>> dp(size, vector<int>(size, 0));
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < i + 1; j++) {
            if (i == 0 && j == 0) {
                dp[0][0] = triangle[0][0];
                continue;
            }
            
            if (j == 0) {
                dp[i][j] = dp[i-1][j] + triangle[i][j];
            } else if (j == i) {
                dp[i][j] = dp[i-1][j-1] + triangle[i][j];
            } else {
                dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
            }
        }
    }
    
    int answer = *max_element(dp[size-1].begin(), dp[size-1].end());
    
    return answer;
}