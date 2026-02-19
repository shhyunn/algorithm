#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int N, M, L;
vector<int> arr;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> L;

    arr.push_back(0);
    arr.push_back(L);

    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(), arr.end());

    int prev = 0;
    int start = 1;
    int end = L;
    int answer = 1e9;

    while (start < end) {
        int mid = (start + end) / 2;
        int total = 0;

        for (int i = 0; i < arr.size() - 1; i++) {
            int diff = arr[i+1] - arr[i];
            total += diff / mid;

            if (diff % mid == 0) total--;
        }

        if (total > M) {
            start = mid + 1;
            

        } else {
            end = mid;
            answer = min(answer, mid);
        }
    }

    cout << answer << endl;

    return 0;
}