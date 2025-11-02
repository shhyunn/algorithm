#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;


int N;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    int x;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap; //최소 힙


    for (int i = 0; i < N; i++) {
        cin >> x;
        if (x == 0) {
            if (heap.empty()) {
                cout << 0 << "\n";
                continue;
            }

            auto [a, b] = heap.top(); heap.pop();
            cout << b << "\n";
            continue;
        }

        heap.push({abs(x), x});
    }
    return 0;
}