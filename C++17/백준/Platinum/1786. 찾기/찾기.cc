#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define MAX 1001

using namespace std;
string T, P;
vector<int> pi;
vector<int> res;
int l1, l2;

int main() {
    getline(cin, T); 
    getline(cin, P);

    l1 = T.size();
    l2 = P.size();

    pi.resize(l2); //패턴 길이로 리사이징

    int j = 0;
    for (int i = 1; i < l2; i++) {
        while (j > 0 && P[i] != P[j]) j = pi[j-1];

        if (P[i] == P[j]) {
            j += 1;
            pi[i] = j;
        }
    }

    j = 0;
    int count = 0;
    for (int i = 0; i < l1; i++) {
        while (j > 0 && T[i] != P[j]) j = pi[j-1];

        if (T[i] == P[j]) {
            if (j == l2 -1) {
                count += 1;
                res.push_back(i-l2+2);
                j = pi[j];
            } else {
                j += 1;
            }
        }
    }
    cout << count << '\n';
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
}