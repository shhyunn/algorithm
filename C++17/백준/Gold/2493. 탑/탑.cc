#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;
vector<int> answers;
vector<int> arr;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //기본 최대힙 -> 최소힙 변경
    
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    answers.resize(n, 0);
    arr.resize(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int idx = n-1;

    while (idx >= 0) {
        int curr_val = arr[idx];

        if (pq.empty()) {
            pq.push({curr_val, idx});
            idx--;
            continue;
        }

        while (!pq.empty() && pq.top().first <= curr_val) {
            answers[pq.top().second] = idx + 1;
            pq.pop();
        }

        pq.push({curr_val, idx});
        idx--;
    }

    for (int i = 0; i < n; i++) {
        cout << answers[i] << " ";
    }
    
    return 0;
}