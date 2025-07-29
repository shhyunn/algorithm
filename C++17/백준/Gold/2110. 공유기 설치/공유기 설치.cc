#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, c;
vector<int> home;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> c;
    home.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> home[i];
    }

    sort(home.begin(), home.end());

    int end = home[n-1] - home[0];
    int start = 1;
    int res = 1;

    while (start <= end) {
        int mid = (start + end) / 2;
        int tmp = 1;
        int prev = home[0];
        for (int i = 1; i < n; i++) {
            if (home[i] - prev >= mid) {
                tmp++;
                prev = home[i];
            }
        }

        if (tmp >= c) {
            res = max(res, mid);
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    cout << res << endl;
    
    return 0;
}
