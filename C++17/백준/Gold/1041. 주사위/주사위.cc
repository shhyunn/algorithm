#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long N, max_num, total_num;

vector<long long> dice;

int main() {

    cin >> N;
    dice.assign(6, 0);

    for (int i = 0; i < 6; i++) {
        cin >> dice[i];
        max_num = max(max_num, dice[i]);
        total_num += dice[i];
    }

    long long one = 1e9;
    long long two = 1e9;
    long long three = 1e9;

    for (int i = 0; i < 6; i++) {
        one = min(one, dice[i]);

        for (int j = i + 1; j < 6; j++) {
            if (i + j == 5) continue;
            two = min(two, dice[i] + dice[j]);

            for (int k = j + 1; k < 6; k++) {
                if (i + k == 5 || j + k == 5) continue;
                three = min(three, dice[i] + dice[j] + dice[k]);
            }
        }
    }

    if (N == 1) {
        cout << total_num - max_num << endl;

    } else {
        long long res = one * ((N-2) * (N-2) + 4 * (N-1) * (N-2)) + two * (4 * (N-2) + 4 * (N-1)) + three * 4;
        cout << res << endl;
    }

    return 0;
}