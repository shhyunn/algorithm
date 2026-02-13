#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector<int> pos_arr;
vector<int> neg_arr;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    
    int num;
    for (int i = 0; i < N; i++) {
        cin >> num;

        if (num > 0) {
            pos_arr.push_back(num);
        } else {
            neg_arr.push_back(num);
        }
    }
    sort(pos_arr.begin(), pos_arr.end(), greater<int>());
    sort(neg_arr.begin(), neg_arr.end());

    int answer = 0;

    int i = 0;

    while (i < pos_arr.size()) {
        if (i + 1 >= pos_arr.size()) {
            answer += pos_arr[i];
            break;
        }

        if (pos_arr[i] * pos_arr[i+1] > pos_arr[i] + pos_arr[i+1]) {
            answer += pos_arr[i] * pos_arr[i+1];
            i += 2;
        } else {
            answer += pos_arr[i];
            i += 1;
        }
    }

    int j = 0;
    while (j < neg_arr.size()) {
        if (j + 1 >= neg_arr.size()) {
            answer += neg_arr[j];
            break;
        }

        if (neg_arr[j] * neg_arr[j+1] > neg_arr[j] + neg_arr[j+1]) {
            answer += neg_arr[j] * neg_arr[j+1];
            j += 2;

        } else {
            answer += neg_arr[j];
            j += 1;
        }
    }

    cout << answer << endl;

    return 0;
}