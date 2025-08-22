#include <bits/stdc++.h>

using namespace std;

int main(){
	int T;
	cin >> T;
	
	for(int i = 0; i < T; i++){
		bool flag = true;
		int N;
		cin >> N;
		vector<string> firstCard(N);
		vector<string> secondCard(N);
		
		for(int i = 0; i < N; i++){
			cin >> firstCard[i];
		}
		
		for(int i = 0; i < N; i++){
			cin >> secondCard[i];
		}
		
		sort(firstCard.begin(), firstCard.end());
		sort(secondCard.begin(), secondCard.end());
		
		for(int i = 0; i < N; i++){
			if(firstCard[i] != secondCard[i]){
				flag = false;
				cout << "CHEATER" << "\n";
				break;
			}
		}
		
		if(flag){
			cout << "NOT CHEATER" << "\n";
		}
	}
}