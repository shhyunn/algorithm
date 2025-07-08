#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<string> words;
vector<char> alphas;
vector<int> num_arr;
char alpha[256];

int calc() {
    int size = num_arr.size();
    int sum = 0;

    for (int i = 0; i < size; i++) {
        alpha[alphas[i]] = num_arr[i];
    }

    for (string word : words) {
        int now = 0;
        for (char w : word) {
            now = now * 10 + alpha[w];
        }
        sum += now;
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    words.resize(N);

    for (int i = 0; i < N; i++) {

        cin >> words[i];

        for (char w : words[i]) {
            alphas.push_back(w);
        }
    }

    sort(alphas.begin(), alphas.end());
    alphas.erase(unique(alphas.begin(), alphas.end()), alphas.end());

    for (int i = 0; i < alphas.size(); i++) {
        num_arr.push_back(9-i);
    }

    sort(num_arr.begin(), num_arr.end());
    int ans = 0;
    do {
        int now = calc();
        if (ans < now) ans = now;
    } while (next_permutation(num_arr.begin(), num_arr.end()));

    cout << ans << endl;
    
    return 0;
}

// g++ example.cpp -o example