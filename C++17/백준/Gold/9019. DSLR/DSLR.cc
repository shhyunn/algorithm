#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>

#define SIZE 200

using namespace std;
int T;
int A; int B;
int visited[10000];

void bfs() {
    queue<pair<int, string>> q;
    q.push({A, ""}); //현재 시작하는 수, 사용한 방법
    visited[A] = 1;

    while (!q.empty()) {
        auto [num, s] = q.front(); q.pop();
        if (num == B) {
            cout << s << "\n";
            return;
        }

        int D, S, L, R;

        D = (num * 2) % 10000;
        if (!visited[D]) {
            visited[D] = 1;
            q.push({D, s + 'D'});
        }

        S = num - 1;
        if (S == -1) S = 9999;
        if (!visited[S]) {
            visited[S] = 1;
            q.push({S, s + 'S'});
        }

        L = (num * 10) % 10000 + (num / 1000);
        if (!visited[L]) {
            visited[L] = 1;
            q.push({L, s + 'L'});
        }

        R = (num % 10) * 1000 + (num / 10);
        if (!visited[R]) {
            visited[R] = 1;
            q.push({R, s + 'R'});
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> A >> B;
        bfs();
        memset(visited, 0, sizeof(visited));
    }

    return 0;
}
