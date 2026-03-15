#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Point {
    int power = 5;
    deque<int> trees;
};

int N, M, K;
vector<vector<Point>> maps;
vector<vector<int>> add_powers;
int move_x[8] = {-1,-1,-1,0,0,1,1,1};
int move_y[8] = {1,0,-1,-1,1,-1,0,1};

void grow_tree() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            deque<int> temp_trees;

            while (!maps[i][j].trees.empty() && maps[i][j].power >= maps[i][j].trees.front()) {
                int v = maps[i][j].trees.front(); maps[i][j].trees.pop_front();
                maps[i][j].power -= v;
                temp_trees.push_back(v+1);
            }

           
            while (!maps[i][j].trees.empty()) {
                maps[i][j].power += maps[i][j].trees.front() / 2;
                maps[i][j].trees.pop_front();
            }

            maps[i][j].trees = temp_trees;
        }
    }
}

void spread_tree(int x, int y) {
    for (int i = 0; i < 8; i++) {
        int cx = x + move_x[i];
        int cy = y + move_y[i];

        if (0 <= cx && cx < N && 0 <= cy && cy < N) {
            maps[cx][cy].trees.push_front(1); //나이 1인 나무 추가
        }
    }
}

void add_tree() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int tree_age : maps[i][j].trees) { //나무 나이
                if (tree_age % 5 == 0) { //5의 배수일 경우
                    spread_tree(i, j);
                }
            }
        }
    }
}

void grow_power() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            maps[i][j].power += add_powers[i][j];
        }
    }
}


int count_tree() {
    int temp = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            temp += maps[i][j].trees.size();
        }
    }

    return temp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;

    maps.assign(N, vector<Point>(N));
    add_powers.assign(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> add_powers[i][j];
        }
    }

    int x, y, z;

    for (int i = 0; i < M; i++) {
        cin >> x >> y >> z;
        maps[x-1][y-1].trees.push_back(z); //나이 저장
        // cout << "나무" << maps[x-1][y-1].trees.front() << endl;
    }

    while (K--) {
         //봄 + 여름
        grow_tree(); //죽은 나무는 양분으로 추가

        //가을
        add_tree(); //나무 번식

        //겨울
        grow_power(); //양분 추가
    }

    int answer = count_tree();

    cout << answer << endl;

   

    return 0;
}