#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;
vector<int> friends;
vector<vector<bool>> rel;
int res = 12000;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    rel.resize(N, vector<bool>(N, false));
    friends.resize(N, 0);

    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        friends[a-1]++;
        friends[b-1]++;
        rel[a-1][b-1] = true;
        rel[b-1][a-1] = true;

    }

    for (int a = 0; a < N - 2; a++) {
        for (int b = a + 1; b < N - 1; b++) {
            if (rel[a][b]) {
                for (int c = b + 1; c < N; c++) {
                    if (rel[a][c] && rel[b][c]) {
                        int tmp = friends[a] + friends[b] + friends[c] - 6;
                        res = min(res, tmp);
                    }
                }
            }
        }
    }

    if (res == 12000) {
        cout << -1 << endl;
        exit(0);
    }

    cout << res << endl;
    
    return 0;
}