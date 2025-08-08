#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	int N;
	
	cin >> N;
	
	vector<vector<string>> board(N, vector<string>(5));
	
	for (int i = 0; i < N; i++){
		for (int j = 0; j < 5; j++){
			cin >> board[i][j];
		}
	}
	
	int maxCost = -1;
	int pic1, pic2;
	
	for (int i = 0; i < N; i++){
		for (int j = i + 1; j < N; j++){
			int cost = 0;
			for (int x = 0; x < 5; x++){
				for (int y = 0; y < 7; y++){
					if (board[i][x][y] == board[j][x][y]) cost++;
				}
			}
			if (maxCost < cost){
				maxCost = cost;
				pic1 = i;
				pic2 = j;
			}
		}
	}
	
	if (pic1 < pic2){
		cout << pic1 + 1 << " " << pic2 + 1 << endl;
	}
	else cout << pic2 + 1 << " " << pic1 + 1 << endl;
	
	return 0;
}