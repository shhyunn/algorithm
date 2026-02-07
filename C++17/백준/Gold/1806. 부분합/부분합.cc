#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    long long s;
    cin >> n >> s;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int left = 0;
    long long sum = 0;
    int answer = 1e9;

    for (int right = 0; right < n; right++) {
        sum += arr[right];

        while (sum >= s) {
            answer = min(answer, right - left + 1);
            sum -= arr[left];
            left++;
        }
    }

    if (answer == 1e9) answer = 0;
    cout << answer << "\n";

    return 0;
}