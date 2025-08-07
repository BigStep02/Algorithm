#include <stdio.h>

int main(){
	int board[9][9] = {0};
	int max = 0, X = 0, Y = 0;
	
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			scanf("%d", &board[j][i]);
		}
	}
	
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			if(max < board[j][i]){
				max = board[j][i];
				X = j+1;
				Y = i+1;
			}
		}
	}
	if(Y == 0 || X == 0){
		Y = 1;
		X = 1;
	}
	printf("%d\n%d %d", max, Y, X);
}