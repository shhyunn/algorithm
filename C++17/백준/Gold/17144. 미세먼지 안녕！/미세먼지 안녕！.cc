#include <iostream>
#include <vector>

using namespace std;

int r, c, t;
int clean_r;
vector<vector<int>> maps;
int move_x[4] = {0,0,-1,1};
int move_y[4] = {-1,1,0,0};

struct Info {
    int r, c, dir, val;
};

void spread_dust() {
    vector<vector<int>> temp_maps = maps;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (maps[i][j] > 0) {
                int divided_value = maps[i][j] / 5;
                int real_divided = 0;
                for (int d = 0; d < 4; d++) {
                    int cx = i + move_x[d];
                    int cy = j + move_y[d];

                    if (0 <= cx && cx < r && 0 <= cy && cy < c && maps[cx][cy] != -1) {
                        real_divided++;
                        temp_maps[cx][cy] += divided_value;
                    }
                }

                temp_maps[i][j] -= (divided_value * real_divided);
            }
        }
    }
    maps = temp_maps;
}

Info proceed_rotate(Info info) {
    int prev = info.val;
    int row = info.r;
    int col = info.c;
    int tmp = 0;

    while (0 <= row && row < r && 0 <= col && col < c && maps[row][col] != -1) {
        tmp = maps[row][col];
        maps[row][col] = prev;
        prev = tmp;

        row += move_x[info.dir];
        col += move_y[info.dir];
    }

    info.r = row - move_x[info.dir];
    info.c = col - move_y[info.dir];
    info.val = prev;


    return info;
}


void rotate_dust(int tmp_r, int dir) {    
    if (dir == 0) {
        Info init = {tmp_r, 1, 1, 0};
        init = proceed_rotate(init);
        init = proceed_rotate({init.r-1, init.c, 2, init.val});
        init = proceed_rotate({init.r, init.c-1, 0, init.val});
        init = proceed_rotate({init.r+1, init.c, 3, init.val});

    } else {
        Info init = {tmp_r, 1, 1, 0};
        init = proceed_rotate(init);
        init = proceed_rotate({init.r+1, init.c, 3, init.val});
        init = proceed_rotate({init.r, init.c-1, 0, init.val});
        init = proceed_rotate({init.r-1, init.c, 2, init.val});
    }
}

void operate_clean() { //공기청정기 작동 함수
    //위쪽 순환
    int upper_r = clean_r;
    rotate_dust(upper_r, 0);

    //아래쪽 순환
    int lower_r = clean_r + 1;
    rotate_dust(lower_r, 1);

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c >> t;

    maps.resize(r, vector<int>(c, 0));

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> maps[i][j];
        }
    }

    for (int i = 0; i < r; i++) {
        if (maps[i][0] == -1) {
            clean_r = i; //청소기 위치 저장
            break;
        }
    }

    for (int i = 0; i < t; i++) {
        //1. 미세먼지 확산
        spread_dust();

        //2. 공기청정기 작동
        operate_clean();
    }
    
    //미세먼지 합 출력
    int answer = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0 ; j < c; j++) {
            if (maps[i][j] == -1) continue;
            answer += maps[i][j];
        }
    }
    cout << answer << endl;
    
    
    return 0;
}