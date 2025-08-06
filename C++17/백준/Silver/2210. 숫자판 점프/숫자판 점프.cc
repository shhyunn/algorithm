#include <iostream>
#include <vector>

using namespace std;

int arr[5][5] = {0,};
bool nums[10][10][10][10][10][10] = {false};
int res = 0;
vector<int> stacks;
int move_x[4] = {0,0,-1,1};
int move_y[4] = {-1,1,0,0};

void dfs(int x, int y, int id) {
    if (id == 5) {
        if (!nums[stacks[0]][stacks[1]][stacks[2]][stacks[3]][stacks[4]][stacks[5]]) {
            nums[stacks[0]][stacks[1]][stacks[2]][stacks[3]][stacks[4]][stacks[5]] = true;
            res++;
        }
        return;
    }
    int cx, cy;
    for (int i = 0; i < 4; i++) {
        cx = x + move_x[i];
        cy = y + move_y[i];

        if ( 0 <= cx && cx < 5 && 0 <= cy && cy < 5) {
            stacks.push_back(arr[cx][cy]);
            dfs(cx, cy, id+1);
            stacks.pop_back();
        }
       
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i =0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i =0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            stacks.push_back(arr[i][j]);
            dfs(i,j,0);
            stacks.pop_back();
        }
    }

    cout << res << endl;
    
    return 0;
}