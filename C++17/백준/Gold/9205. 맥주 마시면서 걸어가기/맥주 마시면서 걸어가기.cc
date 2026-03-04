#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int T, N;
int start_x, start_y, end_x, end_y;
struct Point {
    int x, y;

};

vector<Point> arr;
vector<bool> visited;

int calculate_distance(int prev, int next) {
    Point& prev_point = arr[prev];
    Point& next_point = arr[next];

    int diff = abs(next_point.x - prev_point.x) + abs(next_point.y - prev_point.y);
    return diff;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> N;

        visited.assign(N+2, false); //start, end, store
        arr.clear(); //초기화

        cin >> start_x >> start_y;
        Point p0 = {start_x, start_y};
        arr.push_back(p0); //0번째 인덱스

        for (int i = 0; i < N; i++) {
            Point p;
            cin >> p.x >> p.y;
            arr.push_back(p);
        }

        cin >> end_x >> end_y;
        Point p2 = {end_x, end_y};
        arr.push_back(p2); //마지막 인덱스

        deque<int> st;
        st.push_back(0); //시작 지점
        visited[0] = true;

        string result = "sad";

        while (!st.empty()) {
            int idx = st.front(); st.pop_front();

            if (idx == N+1) { //마지막 포인트라면
                result = "happy";
                break;
            }

            for (int i = 0; i < N+2; i++) {
                if (visited[i]) continue;
                if (calculate_distance(idx, i) <= 1000) {
                    visited[i] = true;
                    st.push_back(i);
                }
            }

        }

        cout << result << endl;


    }


    


    return 0;
    
}
