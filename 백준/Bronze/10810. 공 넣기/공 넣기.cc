#include <stdio.h>

int main(){
	int N, M, startbasket, endbasket, ballnum;
	
	N = 0;
	M = 0;
	startbasket = 0;
	endbasket = 0;
	ballnum = 0;
	
	scanf("%d %d", &N, &M);
	
	int result[N] = {0, };
	
	for(int i = 0; i < M; i++){
		scanf("%d %d %d", &startbasket, &endbasket, &ballnum);
		for(int j = startbasket - 1; j <= endbasket - 1; j++){
			result[j] = ballnum;
		}
	}

	for(int i = 0; i < N; i++){
		printf("%d ", result[i]);
	}
}