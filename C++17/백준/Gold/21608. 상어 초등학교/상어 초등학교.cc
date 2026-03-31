#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long N, max_num, total_num;

int friends[405][405];
int maps[405][405];
int move_x[4] = {-1,1,0,0};
int move_y[4] = {0,0,-1,1};

vector<int> sequence;

void find_seat(int f) {
    int like_num = -1; int empty_num = -1;
    int r = 0; int c = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int tmp_like_num = 0;
            int tmp_empty_num = 0;

            if (maps[i][j]) continue;

            for (int d = 0; d < 4; d++) {
                int cx = i + move_x[d];
                int cy = j + move_y[d];

                if (0 <= cx && cx < N && 0 <= cy && cy < N) {
                    if (maps[cx][cy] == 0) {
                        tmp_empty_num++;

                    } else if (friends[f][maps[cx][cy]] == 1) {
                        tmp_like_num++;
                    }
                }
            }

            if (like_num < tmp_like_num) {
                like_num = tmp_like_num; empty_num = tmp_empty_num; r = i; c = j;

            } else if (like_num == tmp_like_num) {
                if (empty_num < tmp_empty_num) {
                    empty_num = tmp_empty_num; r = i; c = j;

                } else if (empty_num == tmp_empty_num) {
                    if (i < r) {
                        r = i;
                        c = j;
                    } else if (i == r) {
                        if (j < c) c = j;
                    }
                }
            }
        }
    }

    maps[r][c] = f;
}

int calculate_likes() {
    int total_num = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int like_cnt = 0;

            for (int d = 0; d < 4; d++) {
                int cx = i + move_x[d];
                int cy = j + move_y[d];

                if (0 <= cx && cx < N && 0 <= cy && cy < N && friends[maps[i][j]][maps[cx][cy]]) {
                    like_cnt++;
                }
            }

            if (like_cnt != 0) {
                total_num += (pow(10, like_cnt-1));
            }
            
        }
    }

    return total_num;
}

int main() {

    cin >> N;

    int k,a,b,c,d;

    for (int i = 0; i < N*N; i++) {
        cin >> k >> a >> b >> c >> d;

        friends[k][a] = 1;
        friends[k][b] = 1;
        friends[k][c] = 1;
        friends[k][d] = 1;

        sequence.push_back(k);
    }

    for (int s : sequence) {
        find_seat(s);
    }

    int answer = calculate_likes();
   
    cout << answer << endl;

    return 0;
}