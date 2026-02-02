#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int N, M;
int answer;
vector<bool> visited;
unordered_map<int, vector<pair<int, int>>> graph;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; //우선순위 큐 - 최소 힙

bool check_node() {
    for (int i = 0; i < N; i++) {
        if (!visited[i]) return false;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    cin >> M;
    visited.resize(N, false);

    int a, b, c;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        graph[a-1].push_back({c, b-1});
        graph[b-1].push_back({c, a-1});
    }

    pq.push({0, 0}); //거리, 노드 번호

    while (!check_node()) {
        pair<int ,int> tmp = pq.top(); pq.pop();
        if (visited[tmp.second]) continue;

        visited[tmp.second] = true;
        answer += tmp.first;

        for (pair<int, int> a : graph[tmp.second]) {
            pq.push(a);
        }
    }

    cout << answer << endl;

    return 0;
}