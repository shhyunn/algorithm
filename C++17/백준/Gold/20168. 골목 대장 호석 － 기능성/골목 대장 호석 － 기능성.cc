#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

#define N_SIZE 10
#define INT_LIMIT 1e9
using namespace std;

int n, m;

//a - 시작 교차로, b - 도착 교차로, c - 가진 돈
int a, b, c;

int answer = INT_LIMIT;

struct Status {
    int max_value = 0;
    int total_value = 0;
};

vector<vector<int>> paths;
vector<bool> visited;
unordered_map<int, vector<int>> routes;

void func1(int start_node, Status st) {
    if (start_node == b) {
        answer = min(answer, st.max_value); //도착 시 수치심 업데이트
        return;
    }

    Status temp_status = st;
    int path_cost = 0;

    for (int& n : routes[start_node]) {
        if (visited[n]) continue; //이미 방문한 노드라면 skip
        if (temp_status.total_value + paths[start_node][n] > c) continue; //가지고 있는 돈보다 초과되면 skip

        visited[n] = true;

        path_cost = paths[start_node][n];
        temp_status.max_value = max(temp_status.max_value, path_cost);
        temp_status.total_value += path_cost;
        func1(n, temp_status);

        visited[n] = false;
        temp_status = st; //초기 값으로 초기화
    }
}

int main() {
    cin >> n >> m >> a >> b >> c;
    paths.resize(N_SIZE+1, vector<int>(N_SIZE+1, 0));
    visited.resize(N_SIZE+1, false);

    for (int i = 0; i < m; i++) {
        int ts, te, tp;
        cin >> ts >> te >> tp;

        paths[ts][te] = tp;
        paths[te][ts] = tp;
        routes[ts].push_back(te);
        routes[te].push_back(ts);
    }

    Status st1;

    visited[a] = true;
    func1(a, st1);

    if (answer == INT_LIMIT) {
        answer = -1;
    }

    cout << answer << endl;

}