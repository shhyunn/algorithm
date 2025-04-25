#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;

bool is_true(bool a) {
    return a;
}

int solution(int n, vector<vector<int>> costs) {
    unordered_map<int, vector<pair<int, int>>> dic;
    for (auto& c : costs) {
        dic[c[0]].push_back({c[2], c[1]});
        dic[c[1]].push_back({c[2], c[0]});
    }
    
    vector<bool> visited = vector<bool>(n, false);
    int total_cost = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> stack;
    stack.push({0,0});
    
    while (!stack.empty()) {
        auto [weight, node] = stack.top();
        stack.pop();
        
        if (visited[node]) continue;
        total_cost += weight;
        visited[node] = true;
        
        for (auto& a : dic[node]) {
            if (!visited[a.second]) {
                stack.push({a.first, a.second});
            }
        }
        
        if (all_of(visited.begin(), visited.end(), is_true)) {
            break;
        }
    }
    return total_cost;
}