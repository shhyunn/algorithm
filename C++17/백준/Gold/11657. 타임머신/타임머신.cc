#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int from;
    int to;
    int cost;
};

int N, M;
vector<Edge> edges;
vector<long long> dist;

//벨만-포드 알고리즘

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }

    dist.resize(N + 1, 1e18);
    dist[1] = 0;

    // N-1번 relax
    //사이클이 없는 경우 최단 경로는 N-1개, 음수 사이클이 발생하면 제외돰, 반복할 때마다 간선 하나를 더 사용하는 경우가 반복
    //정상적인 그래프라면 N-1번 이후에는 더 이상 거리 갱신이 절대 일어나지 않는다
    for (int i = 1; i <= N - 1; i++) { 
        for (auto &e : edges) {
            if (dist[e.from] == 1e18) continue; //시작 노드가 무제한이면 skip

            if (dist[e.to] > dist[e.from] + e.cost) { //시작 노드 + 비용이 현재 도착노드 비용보다 작다면 갱신
                dist[e.to] = dist[e.from] + e.cost;
            }
        }
    }

    // 음수 사이클 체크
    for (auto &e : edges) {
        if (dist[e.from] == 1e18) continue;

        if (dist[e.to] > dist[e.from] + e.cost) { //거리 갱신이 또 발생한다면 음수 사이클 존재
            cout << -1 << '\n';
            return 0;
        }
    }

    for (int i = 2; i <= N; i++) {
        if (dist[i] == 1e18) cout << -1 << '\n';
        else cout << dist[i] << '\n';
    }

    return 0;
}