#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> ans = vector<int>(n, 1);
    
    for (int& l : lost) {
        ans[l-1]--;
    }
    
    for (int& r : reserve) {
        ans[r-1]++;
    }
    
    for (int i = 0; i < n; i++) {
        if (ans[i] <= 1) continue;
        if (i > 0 && ans[i-1] < 1) {
            ans[i-1]++;
            ans[i]--;
            continue;
        }
        
        if (i < n-1 && ans[i+1] < 1) {
            ans[i+1]++;
            ans[i]--;
            continue;
        }
    }
    
    for (int& a:ans) {
        if (a >= 1) answer++;
    }
    
    return answer;
    
}