#include <iostream>
#include <unordered_map>
#include <vector>

int N, M;
int answer;
using namespace std;

vector<int> visited;
unordered_map<int, vector<int>> dic;

void dfs(int x, int cnt) {
    if (answer) return;
    if (cnt == 5) {
        answer = 1;
        return;
    }

    for (int k : dic[x]) {
        if (visited[k]) continue;
        visited[k] = 1;
        dfs(k, cnt+1);
        visited[k] = 0;
    }
}

int main() {
    cin >> N >> M;

    visited.assign(N, 0);

    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        dic[a].push_back(b);
        dic[b].push_back(a);
    }

    for (int i = 0; i < N; i++) {
        if (answer) break;
        visited[i] = 1;
        dfs(i, 1);
        visited[i] = 0;
    }

    cout << answer << endl;

    return 0;
}