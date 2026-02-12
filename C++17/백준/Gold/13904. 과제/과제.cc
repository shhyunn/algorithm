#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;
int N;
unordered_map<int,vector<int>> maps;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    int d, w;
    int day = 0;
    for (int i = 0; i < N; i++) {
        cin >> d >> w;
        maps[d].push_back(w);
        day = max(d, day);
    }
    int answer = 0;

    priority_queue<int> pq;
    while (day > 0) {
        for (int& v : maps[day]) {
            pq.push(v);
        }

        if (!pq.empty()) {
            answer += pq.top(); pq.pop();
        }
        day--;
    }

    cout << answer << endl;
   
    return 0;
}