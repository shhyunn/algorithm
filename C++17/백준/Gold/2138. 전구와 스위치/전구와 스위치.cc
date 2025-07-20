#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;
int N;
string s; string r;
vector<int> A1;  vector<int> A2; vector<int> B;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    A1.resize(N, 0);
    A2.resize(N, 0);
    B.resize(N, 0);

    cin >> s;
    cin >> r;

    for (int i = 0; i < N; i++) {
        A1[i] = s[i] - '0';
        A2[i] = s[i] - '0';
        B[i] = r[i] - '0';
    }
    int cnt = 0;
    //첫번째 스위치 안누르기
    for (int i = 1; i < N; i++) {
        if (A1[i-1] != B[i-1]) {
            cnt++;
            A1[i-1] = A1[i-1] ^ 1;
            A1[i] = A1[i] ^ 1;
            if (i == N-1) continue;
            A1[i+1] = A1[i+1] ^ 1;
        }

    }

    if (A1[N-1] == B[N-1]) {
        cout << cnt << endl;
        exit(0);
    }

    A2[0] = A2[0] ^ 1;
    A2[1] = A2[1] ^ 1;

    cnt = 1;
    for (int i = 1; i < N; i++) {
        if (A2[i-1] != B[i-1]) {
            cnt++;
            A2[i-1] = A2[i-1] ^ 1;
            A2[i] = A2[i] ^ 1;
            if (i == N-1) continue;
            A2[i+1] = A2[i+1] ^ 1;
        }
    }

    if (A2[N-1] == B[N-1]) {
        cout << cnt << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
