#include <iostream>
#include <vector>
#include <deque>

using namespace std;
int N;
vector<vector<pair<int, int>>> graph;

pair<int, int> bfs(int v) {
    vector<int> visited(N, -1);
    deque<int> stack;
    stack.push_back(v);
    visited[v] = 0;
    int max_distance = 0;
    int far_node = v;

    while (!stack.empty()) {
        int x = stack.front();
        stack.pop_front();

        for (auto g : graph[x]) {
            if (visited[g.first] == -1) {
                visited[g.first] = visited[x] + g.second;
                stack.push_back(g.first);

                if (visited[g.first] > max_distance) {
                    max_distance = visited[g.first];
                    far_node = g.first;
                }
            }
        }
    }

    return {far_node, max_distance};
}

int main() {
    cin >> N;
    graph.resize(N);

    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        while (1) {
            int v; int d;
            cin >> v;

            if (v == -1) {
                break;
            }
            cin >> d;

            graph[n-1].push_back({v-1, d});
        }
    }

    //임의의 두 점 중 거리가 가장 긴 것은? 특정 점에서 가장 거리가 긴 노드에서 다시 가장 거리가 긴 노드 구하기
    int tmp_node = bfs(0).first;
    int answer = bfs(tmp_node).second;
    
    cout << answer << endl;
    return 0;
}