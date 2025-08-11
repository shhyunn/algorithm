
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<string> board;

struct Cross {
    int y, x, len, area;
    vector<pair<int,int>> cells;
};

vector<Cross> crosses;

bool isValid(int y, int x) {
    return y >= 0 && y < N && x >= 0 && x < M && board[y][x] == '#';
}

Cross makeCross(int y, int x, int len) {
    Cross c;
    c.y = y; c.x = x; c.len = len;
    c.area = 1 + 4 * len;
    c.cells.push_back({y, x});
    for (int d = 1; d <= len; d++) {
        c.cells.push_back({y + d, x});
        c.cells.push_back({y - d, x});
        c.cells.push_back({y, x + d});
        c.cells.push_back({y, x - d});
    }
    return c;
}

bool overlap(const Cross &a, const Cross &b) { //하나라도 겹치면 true 반환
    for (auto &p1 : a.cells) { //차지하는 셀이 같은지 확인
        for (auto &p2 : b.cells) {
            if (p1 == p2) return true; // 같으면 true
        }
    }
    return false; //다르면 false
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    board.resize(N);
    for (int i = 0; i < N; i++) cin >> board[i];

    // 1. 모든 십자가 후보 생성
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) { //두 중심 좌표
            if (board[y][x] != '#') continue;
            int maxLen = min({y, N - 1 - y, x, M - 1 - x}); //최대 길이, 십자가 손
            for (int len = 0; len <= maxLen; len++) {
                bool ok = true;
                for (int d = 1; d <= len; d++) {
                    if (!isValid(y + d, x) || !isValid(y - d, x) ||
                        !isValid(y, x + d) || !isValid(y, x - d)) {
                        ok = false;
                        break;
                    }
                }
                if (ok) crosses.push_back(makeCross(y, x, len)); //십자가 만들어서 넣기, 길이마다 만들어서 넣기
            }
        }
    }

    // 2. 모든 쌍 비교
    int ans = 0;
    for (int i = 0; i < crosses.size(); i++) { //십자가 개수만큼 반복
        for (int j = i + 1; j < crosses.size(); j++) { //조합으로 비교
            if (!overlap(crosses[i], crosses[j])) { //십자가가 겹치는지 확인
                ans = max(ans, crosses[i].area * crosses[j].area); //최대 넓이 업데이트
            }
        }
    }

    cout << ans << "\n";
}
