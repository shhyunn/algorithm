#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> N;
        string ss;
        vector<string> arr;

        for (int n = 0; n < N; n++) {
            cin >> ss;
            arr.push_back(ss);
        }

        sort(arr.begin(), arr.end());

        bool is_total_same = false;

        for (int i = 0; i < N-1; i++) {
            if (arr[i].size() > arr[i+1].size()) continue;
            bool is_same = true;

            for (int k = 0; k < arr[i].size(); k++) {
                if (arr[i][k] != arr[i+1][k]) {
                    is_same = false;
                    break;
                }
            }

            if (is_same) {
                is_total_same = true;
                break;
            }
        }

        if (is_total_same) cout << "NO" << endl;
        else cout << "YES" << endl;
    }

    return 0;
}