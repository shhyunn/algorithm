#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int arr[51][51];
int water[51][51];
int move_x[4] = {-1,1,0,0};
int move_y[4] = {0,0,-1,1};
int R, C;
int start_x, start_y;
int end_x, end_y;

struct WaterPos {
    int x, y, cnt;
};

queue<WaterPos> st;
queue<WaterPos> main_st;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> R >> C;

    for (int i = 0; i < 51; i++) {
        for (int j = 0; j < 51; j++) {
            water[i][j] = 1e9;
            arr[i][j] = 1e9;
        }
    }

    string tmp;
    for (int i = 0; i < R; i++) {
        cin >> tmp;
        for (int j = 0; j < C; j++) {
            if (tmp[j] == '*') {
                st.push({i, j, 0}); //물 위치 추가
                water[i][j] = 0;

            } else if (tmp[j] == 'D') { //비버의 굴 위치
                water[i][j] = -1; //물만 이동 불가
                end_x = i; end_y = j;

            } else if (tmp[j] == 'S') { //처음 고슴도치 위치
                start_x = i; start_y = j;
                arr[i][j] = 0;
                main_st.push({i, j, 0});

            } else if (tmp[j] == 'X') { //돌 위치
                arr[i][j] = -1; //돌 이동 불가
                water[i][j] = -1; 
                
            }
        }
       
    }

    // ★ 핵심 수정: 시간 동기화
    int current_time = 0;
    
    while (!main_st.empty()) {
        // 1단계: current_time에 도달한 물을 먼저 확산
        int water_size = st.size();
        for (int i = 0; i < water_size; i++) {
            WaterPos a = st.front();
            st.pop();

            if (a.cnt > current_time) {
                st.push(a);
                continue;
            }

            for (int j = 0; j < 4; j++) {
                int nx = a.x + move_x[j];
                int ny = a.y + move_y[j];

                if (0 <= nx && nx < R && 0 <= ny && ny < C && water[nx][ny] >= 0 && a.cnt + 1 < water[nx][ny]) {
                    water[nx][ny] = a.cnt + 1;
                    st.push({nx, ny, a.cnt + 1});
                }
            }
        }

        // 2단계: current_time에 도달한 고슴도치를 이동
        int beaver_size = main_st.size();
        for (int i = 0; i < beaver_size; i++) {
            WaterPos a = main_st.front();
            main_st.pop();

            if (a.cnt > current_time) {
                main_st.push(a);
                continue;
            }

            for (int j = 0; j < 4; j++) {
                int nx = a.x + move_x[j];
                int ny = a.y + move_y[j];

                if (0 <= nx && nx < R && 0 <= ny && ny < C) {
                    if (nx == end_x && ny == end_y) {
                        cout << a.cnt + 1 << endl;
                        return 0;

                    } else if (water[nx][ny] > a.cnt + 1 && arr[nx][ny] > a.cnt + 1) {
                        arr[nx][ny] = a.cnt + 1;
                        main_st.push({nx, ny, a.cnt + 1});
                    }
                }
            }
        }
        
        current_time++;
    }

    cout << "KAKTUS" << endl;

    return 0;
}