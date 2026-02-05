#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int N, M;
vector<vector<int>> maps;
vector<int> dest;
unordered_map<int , vector<int>> dic;

void func1(int i) {
    deque<int> st;
    st.push_back(i);

    while (!st.empty()) {
        int t = st.front(); st.pop_front();

        for (int j : dic[t]) {
            if (maps[i][j] > 0) continue;
            maps[i][j] = 1;
            st.push_back(j);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    maps.assign(N, vector<int>(N, 0));
    dest.assign(M, 0);

    int val;
    
    for (int i = 0; i < N; i++) {
        maps[i][i] = 1;
        for (int j = 0; j < N; j++) {
            cin >> val;
            if (val == 1) {
                dic[i].push_back(j);
            }
        }
    }

    for (int i = 0; i < M; i++) {
        cin >> dest[i];
    }

    for (int i = 0; i < N; i++) {
        func1(i);
    }

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         cout << maps[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    string answer = "YES";
    for (int i = 0; i < M - 1; i++) {
        int a = dest[i];
        int b = dest[i+1];

        if (maps[a-1][b-1] == 0) {
            answer = "NO";
            break;
        }
    }

    cout << answer << endl;

    return 0;
}