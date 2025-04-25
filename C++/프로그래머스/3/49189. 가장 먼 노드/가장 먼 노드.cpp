#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<int> distance(n, 20001);
    vector<bool> visited(n);
    vector<vector<int>> graph(n);
    
    for (auto& e : edge) {
        graph[e[0]-1].push_back(e[1] - 1);
        graph[e[1]-1].push_back(e[0]-1);
    }
    
    deque<pair<int, int>> stack;
    stack.push_back({0, 0});
    visited[0] = true;
    distance[0] = 0;
    
    while (!stack.empty()) {
        auto [v, cnt] = stack.front();
        stack.pop_front();
        
        for (auto& i : graph[v]) {
            if (!visited[i]) {
                distance[i] = cnt + 1;
                visited[i] = true;
                stack.push_back({i, cnt+1});
            }
        }   
    }
    
    int max_value = *max_element(distance.begin(), distance.end());
    for (int& d : distance) {
        if (d == max_value) answer++;
    }
    
    
    return answer;
}