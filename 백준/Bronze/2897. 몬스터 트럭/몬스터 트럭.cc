#include <bits/stdc++.h>

using namespace std;

int X_count(const vector<string> &board, int x, int y){
    int cnt = 0;
    if(board[x][y] == 'X') cnt++;
    if(board[x + 1][y] == 'X') cnt++;
    if(board[x][y + 1] == 'X') cnt++;
    if(board[x + 1][y + 1] == 'X') cnt++;

    return cnt;
}

int main() {
    int R, C;
    cin >> R >> C;

    vector<string> board(R);
    vector<int> brokeCar(5);

    for(int i = 0; i < R; i++){
        cin >> board[i];
    }

    for(int i = 0; i < R - 1; i++){
        for(int j = 0; j < C - 1; j++){
            if(board[i][j] == '#' or board[i + 1][j] == '#' or board[i][j + 1] == '#' or board[i + 1][j + 1] == '#') continue;
            brokeCar[X_count(board, i, j)]++;
        }
    }

    for(int i = 0; i < brokeCar.size(); i++){
        cout << brokeCar[i] << "\n";
    }

    return 0;
}