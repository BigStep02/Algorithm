#include <bits/stdc++.h>
 
using namespace std;

int main(){
	int N;
	string S;
	cin >> N >> S;
	int Wlever = 0, deadCnt = 0;
	bool Plever = false; // false일때 5명 죽음 true일때 1명 죽음 
	
	for(int i = 0; i < N; i++){
		if(Wlever == 1 and S[i] == 'P'){
			deadCnt = 6;
		}
		if(S[i] == 'W'){
			Wlever++;
			if(Wlever == 2){
				if(deadCnt == 6) break;
				(!Plever)? deadCnt += 5 : deadCnt += 1;
				break;
			}
			continue;
		}
		if(Wlever == 0 and S[i] == 'P'){
			Plever = !Plever;
		}
	}
	
	(Wlever == 2)? cout << deadCnt : cout << 0;
}