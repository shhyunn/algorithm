#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> v;
int n;
int sum;

vector<string> split(string ss, char dots) {
    vector<string> res;
    string temp = "";

    for (char c : ss) {
        if (c == dots) {
            if (temp.length() > 0) {
                res.push_back(temp);
                temp = "";
            } 
        } else {
            temp += c;
        }
    }

    if (temp.length() > 0) {
        res.push_back(temp);
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string strr;
    cin >> strr;

    vector<string> tt = split(strr, '-');
    int total = 0;
    vector<string> init = split(tt[0], '+');

    for (string& k : init) {
        total += stoi(k);
    }

    for (int i = 1; i < tt.size(); i++) {
         vector<string> init = split(tt[i], '+');
         for (string& k : init) {
            total -= stoi(k);
        }
    }

    cout << total << endl;
   
    return 0;
}