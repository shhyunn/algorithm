#include <iostream>
#include <vector>
#include <queue>

#define MAX_VALUE 100000
using namespace std;

int N, K;
vector<int> steps;
vector<int> prev_steps;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;

    steps.assign(MAX_VALUE+1, 1e9);   
    prev_steps.assign(MAX_VALUE+1, -1);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    pq.push({0, N});
    prev_steps[N] = -1;
    steps[N] = 0;

    while (!pq.empty()) {
        pair<int, int> a = pq.top(); pq.pop();

        if (a.first > steps[a.second]) { //이미 최적 경로로 되어있다면
            continue;
        }

        if (a.second == K) break;

        int next_arr[3] = {a.second-1, a.second+1, a.second*2};

        for (int& v : next_arr) {
            if (0 <= v && v <= MAX_VALUE && a.first + 1 < steps[v]) {
                steps[v] = a.first + 1;
                pq.push({a.first+1, v});
                prev_steps[v] = a.second;
            }
        }
    }
    int q = K;
    vector<int> res;
    while (q != -1) {
        res.push_back(q);
        q = prev_steps[q];
    }

    cout << steps[K] << "\n";

    for (int i = res.size() - 1; i >= 0; i--) {
        cout << res[i] << " ";
    }

    return 0;
}