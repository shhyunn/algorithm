#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int N, M;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;

    priority_queue<long long, vector<long long>, greater<>> pq;
    
    long long num;
    for (int i = 0; i < N; i++) {
        cin >> num;
        pq.push(num);
    }

    int cnt = M;
    while (cnt > 0) {
        long long t1 = pq.top(); pq.pop();
        long long t2 = pq.top(); pq.pop();

        long long t3 = t1 + t2;
        pq.push(t3);
        pq.push(t3);
        cnt--;
    }
    
    long long answer = 0;
    while (!pq.empty()) {
        answer += pq.top(); pq.pop();
    }

    cout << answer << endl;

    return 0;
}