#include <vector>
#include <iostream>
#include <deque>
using namespace std;

int n, k;
vector<bool> visited;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;

    deque<pair<int, int>> stack;

    visited.resize(100001, false);
    visited[n] = true;
    stack.push_back({n, 0});

    while (!stack.empty()) {
        pair<int ,int> t = stack.front(); stack.pop_front();
        if (t.first == k) {
            cout << t.second << endl;
            break;
        }

        if (t.first - 1 >= 0 && !visited[t.first-1]) {
            visited[t.first-1] = true;
            stack.push_back({t.first-1, t.second+1});
        }

        if (t.first + 1 <= 100000 && !visited[t.first+1]) {
            visited[t.first+1] = true;
            stack.push_back({t.first+1, t.second+1});
        }

        if (t.first * 2 <= 100000 && !visited[t.first*2]) {
            visited[t.first*2] = true;
            stack.push_back({t.first*2, t.second+1});
        }
    }

    return 0;
}