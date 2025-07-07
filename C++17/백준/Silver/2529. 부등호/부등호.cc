#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int K;
vector<char> signs;

bool check(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        if (signs[i] == '>' && arr[i] < arr[i+1]) return false;
        if (signs[i] == '<' && arr[i] > arr[i+1]) return false;
    }
    return true;
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> K;
    signs.resize(K);

    for (int i = 0; i < K; i++) {
        cin >> signs[i];
    }

    vector<int> small(K+1);
    vector<int> big(K+1);

    for (int i = 0; i < K+1; i++) {
        small[i] = i;
        big[i] = 9 - i;
    }

    do {
        if (check(small)) break;
    } while (next_permutation(small.begin(), small.end()));

    do {
        if (check(big)) break;
    } while (prev_permutation(big.begin(), big.end()));

    for (int i = 0; i <= K; i++) cout << big[i];
    cout << "\n";
    for (int i = 0; i <= K; i++) cout << small[i];

    
    return 0;
}