#include <bits/stdc++.h>

using namespace std;

void BFS(queue<int> &q, int *board, int A, int B, int N, int M){
    while(board[M] == 0){
        int next = q.front();
        q.pop();
        for(int i : {next + 1, next - 1, next + A, next + B, next - A, next - B, next * A, next * B}){
            if(i < 0 || i > 100000) continue;
            if(board[i] != 0) continue;
            board[i] = board[next] + 1;
            q.push(i);
        }
    }   
}

int main(){
    int A, B, N, M;
    cin >> A >> B >> N >> M;

    int* board = new int[100001]();

    queue<int> q;

    board[N] = 1;
    q.push(N);
    BFS(q, board, A, B, N, M);

    cout << board[M] - 1;

    delete[] board;
}