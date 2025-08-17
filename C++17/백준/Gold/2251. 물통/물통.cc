#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

struct Item {
    int A, B, C;
};

int x,y,z;
bool visited[201][201][201] = {false, };
set<int> res;
queue<Item> stacks;

void push_next(int a, int b, int c) {
    if (!visited[a][b][c]) {
        visited[a][b][c] = true;
        Item s;
        s.A = a; s.B = b; s.C = c;
        stacks.push(s);
        if (a == 0) res.insert(c);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> x >> y >> z;

    Item s;
    s.A = 0;
    s.B = 0;
    s.C = z;

    stacks.push(s);
    visited[0][0][z] = true;
    res.insert(z);

    while (!stacks.empty()) {
        Item k = stacks.front(); stacks.pop();
        int a = k.A; int b = k.B; int c = k.C;

        
        int min_value;

        //A -> B
        min_value = min(y-b, a);
        push_next(a-min_value, b + min_value, c);

        //A -> C
        min_value = min(z-c, a);
        push_next(a-min_value, b, c + min_value);

        //B -> A
        min_value = min(x-a, b);
        push_next(a+min_value, b-min_value, c);

        //B -> C
        min_value = min(z-c, b);
        push_next(a, b-min_value, c + min_value);

        //C -> A
        min_value = min(x-a, c);
        push_next(a+min_value, b, c-min_value);

        //C -> B
        min_value = min(y-b, c);
        push_next(a, b+min_value, c-min_value);
    }

    for (int a : res) {
        cout << a << " ";
    }
    cout << "\n" << endl;
    
}