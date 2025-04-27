#include <string>
#include <vector>
#include <unordered_map>
#include <deque>

using namespace std;

unordered_map<int, vector<int>> graph;
vector<int> visited;
vector<int> distances;

void bfs(int d) {
    deque<pair<int, int>> stack;
    stack.push_back({d, 0});
    visited[d] = true;
    distances[d] = 0;
    
    while (!stack.empty()) {
        auto [v, level] = stack.front();
        stack.pop_front();
        
        for (auto& g : graph[v]) {
            if (!visited[g]) {
                stack.push_back({g, level + 1});
                visited[g] = true;
                distances[g] = level + 1;
            }
        }
    }
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    visited.resize(n+1, false);
    distances.resize(n+1, -1);
    
    for (auto& r : roads) {
        graph[r[0]].push_back(r[1]);
        graph[r[1]].push_back(r[0]);
    }
    
    bfs(destination);
    
    for (int& s : sources) {
        answer.push_back(distances[s]);
    }

    return answer;
}