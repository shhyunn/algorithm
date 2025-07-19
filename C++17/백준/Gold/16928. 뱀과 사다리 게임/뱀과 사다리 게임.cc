#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
int N; int M;
int nexts[101];
bool visited[101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;

    memset(visited, false, sizeof(visited));
    
    for (int i = 0; i < 101; i++) {
        nexts[i] = i;
    }
    int x; int y;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        nexts[x] = y;
    }

    int u; int v;
    for (int i = 0; i < M; i++) {
        cin >> u >> v;
        nexts[u] = v;
    }

    queue<pair<int, int>> stack;
    stack.push({1, 0});
    visited[1] = true;

    while (!stack.empty()) {
        auto [k, cnt] = stack.front(); stack.pop();
        if (k == 100) {
            cout << cnt << endl;
            break;
        }

        for (int i = 1; i < 7; i++) {
            if (k + i <= 100 && !visited[k+i]) {
                stack.push({nexts[k+i], cnt+1});
                visited[k+i] = true;
                visited[nexts[k+i]] = true;
            }
        }
    }

    return 0;
}
