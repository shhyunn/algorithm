#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
int a, b, k, g;
int answer = 1e9;

vector<int> godula_paths;
vector<vector<int>> board;
vector<vector<int>> times;
vector<vector<pair<int, int>>> godula_times;

int check_time(int curr, int next, int curr_time) {
    if (godula_times[curr][next].second > curr_time && godula_times[curr][next].first <= curr_time) {
        return times[curr][next] + (godula_times[curr][next].second - curr_time);
    }

    return times[curr][next];
}

void dijkstra() {
    const int INF = 1e9;
    vector<int> dist(n+1, INF); //각 노드의 거리 저장

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq; //최소 우선순위 큐

    dist[a] = k; //a까지의 거리 k
    pq.push({k, a}); //우선순위 큐에 저장

    while (!pq.empty()) {
        auto [curr_time, node] = pq.top();
        pq.pop();

        if (dist[node] < curr_time) continue; //이미 최소 노드가 있다면 종료
        if (node == b) break; //b라면 중단

        for (int next_node : board[node]) { //다음 노드 순회
            int cost = check_time(node, next_node, curr_time);
            int next_time = curr_time + cost;

            if (next_time < dist[next_node]) { //기존 거리보다 작다면 업데이트
                dist[next_node] = next_time;
                pq.push({next_time, next_node});
            }
        }
    }

    answer = dist[b];
}
    
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    cin >> a >> b >> k >> g;

    godula_paths.resize(g, 0);
    times.resize(n+1, vector<int>(n+1, 0)); //교차로를 잇는 도로의 시간
    godula_times.resize(n+1, vector<pair<int, int>>(n+1, {-1, -1}));
    board.resize(n+1);

    for (int i = 0; i < g; i++) {
        cin >> godula_paths[i]; //고둘라 이동 경로
    }

    int u, v, l;

    for (int i = 0; i < m; i++) {
        cin >> u >> v >> l;
        board[u].push_back(v); //교차로 연결
        board[v].push_back(u);
        times[u][v] = l; //교차로 연결 도로 시간 저장
        times[v][u] = l;
    }

    int prev_path = 0;
    int total_time = 0;

    for (int i = 0; i < g; i++) {
        if (prev_path == 0) {
            prev_path = godula_paths[i];
            continue;
        }

        godula_times[prev_path][godula_paths[i]] = {total_time, total_time + times[prev_path][godula_paths[i]]};
        godula_times[godula_paths[i]][prev_path] = {total_time, total_time + times[prev_path][godula_paths[i]]};
        total_time += times[prev_path][godula_paths[i]];
        prev_path = godula_paths[i];
    }

    dijkstra();

    cout << answer - k << endl;
    
    
    return 0;
}