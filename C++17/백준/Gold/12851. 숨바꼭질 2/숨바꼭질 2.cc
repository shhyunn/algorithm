#include <vector>
#include <iostream>
#include <deque>
using namespace std;

int n, k;
vector<int> visited;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;

    deque<pair<int, int>> stack;

    visited.resize(100001, 1e9);
    visited[n] = 0;
    stack.push_back({n, 0});
    int time = 1e9;
    int answer = 0;

    while (!stack.empty()) {
        pair<int ,int> t = stack.front(); stack.pop_front();
        if (t.second > time) break;

        if (t.first == k && t.second <= time) {
            time = t.second;
            answer++;
            continue;
        }

        if (t.first - 1 >= 0 && t.second <= visited[t.first-1]) {
            visited[t.first-1] = t.second;
            stack.push_back({t.first-1, t.second+1});
        }

        if (t.first + 1 <= 100000 && t.second <= visited[t.first+1]) {
            visited[t.first+1] = t.second;
            stack.push_back({t.first+1, t.second+1});
        }

        if (t.first * 2 <= 100000 && t.second <= visited[t.first*2]) {
            visited[t.first*2] = t.second;
            stack.push_back({t.first*2, t.second+1});
        }
    }

    cout << time << "\n" << answer << endl;

    return 0;
}