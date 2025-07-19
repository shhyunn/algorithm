#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>

#define SIZE 200

using namespace std;
int N;
int r1; int c1; int r2; int c2;
int move_x[6] = {-2,-2,0,0,2,2};
int move_y[6] = {-1,1,-2,2,-1,1};
bool visited[SIZE][SIZE];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;

    memset(visited, false, sizeof(visited));

    cin >> r1 >> c1 >> r2 >> c2;

    queue<tuple<int, int, int>> stack;
    stack.push({r1,c1, 0});
    visited[r1][c1] = true;

    bool find = false;

    while (!stack.empty()) {
        auto [r, c, cnt] = stack.front(); stack.pop();
        if (r == r2 && c == c2) {
            find = true;
            cout << cnt << endl;
            break;
        }
        int cr; int cc;
        for (int i = 0; i < 6; i++) {
            cr = r + move_x[i];
            cc = c + move_y[i];

            if (0 <= cr && cr < SIZE && 0 <= cc && cc < SIZE && !visited[cr][cc]) {
                stack.push({cr, cc, cnt+1});
                visited[cr][cc] = true;
            }
        }
    }
    if (!find) {
        cout << -1 << endl;
    }
    

    return 0;
}