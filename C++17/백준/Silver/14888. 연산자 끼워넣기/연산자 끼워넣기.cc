#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> nums;
vector<int> ex;

int calc() {
    int size = ex.size();
    int ans = nums[0];

    for (int i = 0; i < size; i++) {
        if (ex[i] == 0) {
            ans = ans + nums[i+1];
        } else if (ex[i] == 1) {
            ans = ans - nums[i+1];
        } else if (ex[i] == 2) {
            ans = ans * nums[i+1];
        } else {
            ans = ans / nums[i+1];
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    nums.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    for (int i = 0; i < 4; i++) {
        int cnt;
        cin >> cnt;
        for (int c = 0; c < cnt; c++) {
            ex.push_back(i);
        }
    }

    sort(ex.begin(), ex.end());

    int min_val = 1e9;
    int max_val = -1e9;
    do {
        int tmp = calc();
        min_val = min(min_val, tmp);
        max_val = max(max_val, tmp);
    } while (next_permutation(ex.begin(), ex.end()));

    cout << max_val << "\n" << min_val << endl;
    
    return 0;
}