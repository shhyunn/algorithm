#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

int N, M, T;
unordered_map<int ,vector<pair<int ,int>>> maps;
vector<int> dist;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> T;

    int u, v, h;
    for (int i = 0; i < M; i++) {
        cin >> u >> v >> h;
        maps[u-1].push_back({h, v-1});
    }

    int s, e, answer;
    for (int i = 0; i < T; i++) {
        cin >> s >> e;

        priority_queue<pair<int ,int>, vector<pair<int ,int>>, greater<>> pq;
        dist.assign(N, 1e9);
        dist[s-1] = 0;
        pq.push({0, s-1});
        answer = -1;

        while (!pq.empty()) {
            auto [height, node] = pq.top(); pq.pop();

            if (dist[node] < height) continue;

            if (node == e-1) {
                answer = height;
                break;
            }

            for (auto [height2, node2] : maps[node]) {
                int max_val = max(height2, height);

                if (dist[node2] > max_val) {
                    dist[node2] = max_val;
                    pq.push({max_val, node2});
                }
            }
        }

        cout << answer << "\n";
    }
   
    return 0;
}