#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int M, N;
vector<vector<int>> maps;
vector<vector<int>> costs;

int move_x[4] = {-1,1,0,0};
int move_y[4] = {0,0,-1,1};

struct Node {
    int cost, x, y;

    bool operator>(const Node& other) const {
        return cost > other.cost;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N;
    maps.assign(N, vector<int>(M, 0));
    costs.assign(N, vector<int>(M, 1e9));

    string ss;
    for (int i = 0; i < N; i++) {
        cin >> ss;
        for (int j = 0; j < ss.size(); j++) {
            maps[i][j] = ss[j] - '0';
        }
    }

    priority_queue<Node, vector<Node>, greater<>> pq;

    pq.push({0, 0, 0});
    costs[0][0] = 0;

    while (!pq.empty()) {
        Node t = pq.top(); pq.pop();

        if (t.x == N-1 && t.y == M-1) {
            cout << t.cost << endl;
            break;
        }

        if (t.cost > costs[t.x][t.y]) continue;

        for (int d = 0; d < 4; d++) {
            int cx = t.x + move_x[d];
            int cy = t.y + move_y[d];

            if (0 <= cx && cx < N && 0 <= cy && cy < M && t.cost + maps[cx][cy] < costs[cx][cy]) {
                costs[cx][cy] = t.cost + maps[cx][cy];
                pq.push({t.cost + maps[cx][cy], cx, cy});
            }
        }
    }
   
    return 0;
}