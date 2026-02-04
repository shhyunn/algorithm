#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> arr;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    arr.assign(N, 0);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
   
    sort(arr.begin(), arr.end());

    int left_pointer = 0;
    int right_pointer = N-1;
    int diff;
    int ans1, ans2;
    int ans_diff = 2.1e9;

    while (left_pointer < right_pointer) {
        diff = arr[right_pointer] + arr[left_pointer];

        if (abs(diff) < ans_diff) {
            ans_diff = abs(diff);
            ans1 = left_pointer;
            ans2 = right_pointer;
        }

        if (diff == 0) break;

        if (diff > 0) right_pointer--;
        else left_pointer++;
    }

    cout << arr[ans1] << " " << arr[ans2] << endl;
    return 0;
}