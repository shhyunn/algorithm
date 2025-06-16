#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N; int M;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    vector<int> isDone(N+1, 0);
    vector<vector<int>> seq(N+1);
    priority_queue<int, vector<int>, greater<int>> pq;
    int A, B;

    for (int i = 0; i < M; i++) {
        cin >> A >> B;
        isDone[B]++; //풀어야 하는 갯수
        seq[A].push_back(B);

    }

    for (int i = 1; i < N+1; i++) {
        if (isDone[i] == 0) {
            pq.push(i);
        }
    }

    while (!pq.empty()) {
        int k = pq.top(); pq.pop();
        cout << k << " ";

        for (int i = 0; i < seq[k].size(); i++) {
            int next = seq[k][i];
            isDone[next]--;

            if (isDone[next] == 0) {
                pq.push(next);
            }
        }
    }

    cout << endl;
    return 0;
}