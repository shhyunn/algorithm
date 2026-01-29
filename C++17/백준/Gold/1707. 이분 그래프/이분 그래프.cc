#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int K;
int V, E;
int u, w;
int answer = 1;
unordered_map<int, vector<int>> node_maps;
vector<int> group_arr;
vector<bool> visited;

void func1(int node, int group_num) {
    visited[node] = true;
    int next_group_num = group_num == 0 ? 1 : 0;

    for (int next_node : node_maps[node]) {
        // if (visited[next_node]) continue;

        if (group_arr[next_node] == -1) {
            group_arr[next_node] = next_group_num;
            func1(next_node, next_group_num);

        } else if (group_arr[next_node] != next_group_num) {
            answer = 0;
            break;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> K;
    int small_value, large_value;
    for (int k = 0; k < K; k++) {
        cin >> V >> E;
        unordered_map<int, vector<int>> tmp;
        node_maps = tmp; //간선 연결 초기화
        group_arr.assign(V+1, -1);
        visited.assign(V+1, false);

        for (int e = 0; e < E; e++) {
            cin >> u >> w;
            
            node_maps[u].push_back(w);
            node_maps[w].push_back(u);
        }

        for (int i = 1; i <= V; i++) {
            if (visited[i]) continue;
            group_arr[i] = 0;
            func1(i, 0);
            if (answer == 0) break;
        }

        if (answer == 1) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }

        answer = 1;
    }

    return 0;
}