#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n;
vector<vector<int>> answers;

void func1(int a, int b, int size) {
    if (size == 1) {
        answers[a][b] = 1;
        return;
    }

    int divided_size = size / 3;

    for (int i = a + divided_size; i < a + 2 * divided_size; i++) {
        for (int j = b + divided_size; j < b + 2 * divided_size; j++) {
            answers[i][j] = 0; //공백
        }
    }

    for (int i = a; i < a + size; i += divided_size) {
        for (int j = b; j < b + size; j += divided_size) {
            if (answers[i][j] == 0) continue;
            func1(i, j, divided_size);
        }
    }
}

int main() {
    cin >> n;
    answers.resize(n, vector<int>(n, -1));

    func1(0,0,n); //시작 위치 w, c, n

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (answers[i][j] == 0) {
                cout << " ";
            } else {
                cout << "*";
            }
        }
        cout << "\n";
    }
    return 0;
}