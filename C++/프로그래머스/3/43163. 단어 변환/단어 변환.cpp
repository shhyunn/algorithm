#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int bfs(string& begin, string& target, vector<string>& words, int n) {
    //타겟 넘버가 없을 경우
    if (find(words.begin(), words.end(), target) == words.end()) return 0;
    
    queue<pair<int, int>> stack;
    vector<bool> visited(n, false);
    
    stack.push({n-1, 0});
    visited[n-1] = true;
    
    int sz = begin.size();
    
    while (!stack.empty()) {
        auto [id, ans] = stack.front();
        stack.pop();
        
        if (words[id] == target) return ans;
        
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            
            int cnt = 0;
            for (int j = 0; j < sz; j++) {
                if (words[i][j] == words[id][j]) cnt++;
            }
            
            if (cnt == sz - 1) {
                stack.push({i, ans + 1});
                visited[i] = true;
            }
        }
    }
    
    return 0;
    
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    words.push_back(begin);
    answer = bfs(begin, target, words, words.size());
    
    return answer;
}