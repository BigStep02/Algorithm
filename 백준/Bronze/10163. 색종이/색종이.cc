#include <iostream>
#include <vector>

using namespace std;

int main(){
	int N;
	
	cin >> N;
	
	vector<vector<int>> board(1002, vector<int>(1002, 0));
	
	for (int i = 1; i < N + 1; i++){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		for (int x = b; x < b + d; x++){
			for (int y = a; y < a + c; y++){
				board[x][y] = i;
			}
		}
	}
	
	vector<int> result(N, 0);
	
	for (int i = 0; i < 1002; i++){
		for (int j = 0; j < 1002; j++){
			if (board[i][j] != 0){
				result[board[i][j] - 1]++;
			}
		}
	}
	
	for (int i = 0; i < N; i++){
		cout << result[i] << "\n";
	}
	
	cout << endl;
	
	return 0;
}