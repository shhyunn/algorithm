#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> arr;
vector<int> seq;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    arr.resize(N, vector<int>(N, 0));
    seq.resize(N, 0);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = N / 2; i < N; i++) {
        seq[i] = 1;
    }
    int min_value = 1e9;
    do {
        int start = 0;
        int link = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i+1; j < N; j++) {
                if (seq[i] == seq[j]) {
                    if (seq[i] == 0) {
                        start += arr[i][j];
                        start += arr[j][i];
                    } else {
                        link += arr[i][j];
                        link += arr[j][i];
                    }
                } 
            }
        }
        min_value = min(min_value, abs(start - link));

    } while (next_permutation(seq.begin(), seq.end()));

    cout << min_value << endl;
    
    return 0;
}