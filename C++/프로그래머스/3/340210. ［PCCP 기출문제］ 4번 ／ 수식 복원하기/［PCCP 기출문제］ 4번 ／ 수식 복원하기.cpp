#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;
vector<bool> visited;
vector<bool> number;

int to_decimal(int k, string& numStr) {
    int result = 0;
    
    for (char c : numStr) {
        result = result * k + (c - '0');
    }
    return result;
}

string toBaseN(int num, int base) {
    if (num == 0) return "0";
    string result;
    while (num > 0) {
        result = char('0' + num % base) + result;
        num /= base;
    }
    return result;
}

vector<string> solution(vector<string> expressions) {
    vector<string> answer;
    int size = expressions.size();
    visited.resize(size, false);
    number.resize(10, true);
    
    string a; string b; string c;
    char op; char eq;
    
    for (int i = 0; i < size; i++) {
        auto& ex = expressions[i];
        
        istringstream ss(ex);
        ss >> a >> op >> b >> eq >> c;
        int max_value = 0;
        
        for (auto& cc : a) {
            // number[cc - '0'] = false;
            max_value = max(cc- '0', max_value);
        }
        
        for (auto& cc : b) {
            // number[cc - '0'] = false;
            max_value = max(cc- '0', max_value);
        }
        
        
        
        if (c == "X") {
            for (int r = 0; r <= max_value; r++) {
                number[r] = false;
            }
            
            continue;
        }
        
        for (auto& cc : c) {
            // number[cc - '0'] = false;
            max_value = max(cc- '0', max_value);
        }
        
        for (int r = 0; r <= max_value; r++) {
            number[r] = false;
        }
        
        visited[i] = true;
        
        // cout << "ex" << a << " " << b << " " << c << '\n';
        
        for (int n = 2; n < 10; n++) {
            // cout << "true" << number[n] << '\n';
            if (!number[n]) continue;
            
            if (op == '+') {
                // cout << to_decimal(n, a) << " " << to_decimal(n, b) << " " << to_decimal(n, c-'0') << '\n';
                if (toBaseN(to_decimal(n, a) + to_decimal(n, b), n) != toBaseN(to_decimal(n, c), n)) {
                    // cout << "n" << n << '\n';
                    number[n] = false;
                }
            }
            
            if (op == '-') {
                 if (toBaseN(to_decimal(n, a) - to_decimal(n, b), n) != toBaseN(to_decimal(n, c), n)) {
                    // cout << "n" << n << '\n';
                    number[n] = false;
                }
            } 
        }
    }
    
    for (int i = 0; i < size; i++) {
        if (visited[i]) continue;
        auto& ex = expressions[i];

        istringstream ss(ex);
        ss >> a >> op >> b >> eq >> c;

        int res = -1;
        int tmp = 0;
        bool correct = false;
        
        for (int n = 2; n < 10; n++) {
            if (!number[n]) continue;
            
            
            if (op == '+') {
                tmp = stoi(toBaseN(to_decimal(n, a) + to_decimal(n, b), n));
            } else {
                tmp = stoi(toBaseN(to_decimal(n, a) - to_decimal(n, b), n));
            }
            // cout << "i" << i + 1 << "n" << n << "tmp" << tmp <<'\n';

            if (res > 0 && res != tmp) {
                correct = false;
            } else {
                res = tmp;
                correct = true;
            }
        }
        
        string ex2 = ex.substr(0, ex.size() - 1);
        
        if (res == -1 || !correct) {
            ex2 += '?';
        } else {
            ex2 += to_string(res);
        }
        
        answer.push_back(ex2);
    }
    
    return answer;
}