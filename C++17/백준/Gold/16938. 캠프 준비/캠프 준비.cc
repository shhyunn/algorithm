#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, L, R, X;
vector<int> arr;
vector<int> temp;
int res = 0;
int len_arr = 0;

void counting(int index, int count, int sums) {
    if (index == len_arr) {
        if (count >= 2 && temp[count-1] - temp[0] >= X && sums >= L && sums <= R) {
            res++;
        }
        return;
    }

    temp.push_back(arr[index]);
    counting(index+1, count+1, sums + arr[index]);
    temp.pop_back();

    counting(index+1, count, sums);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> L >> R >> X;
    arr.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    len_arr = arr.size();

    sort(arr.begin(), arr.end());

    counting(0, 0, 0);

    cout << res << endl;
    
    return 0;
}