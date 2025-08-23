#include <bits/stdc++.h>

using namespace std;

int main(){
	int T;
	cin >> T;
	
	for(int testCase = 0; testCase < T; testCase++){
		int N;
		cin >> N;
		
		vector<int> parti(N);
		
		for(int i = 0; i < N; i++){
			cin >> parti[i];
		}
		
		int runner;
		cin >> runner;
		
		int certif = 0, bestRunner = 0, bestHour = 10, bestMin = 10;
		
		for(int i = 0; i < runner; i++){
			int a, b, c;
			cin >> a >> b >> c;
			auto it = find(parti.begin(), parti.end(), a);
			if(it == parti.end() or b == -1) continue;
			if(b < 6 or (b == 6 and c == 0)){
				 certif++;
				 if(bestHour > b or (bestHour == b and bestMin > c)){
				 	bestHour = b;
				 	bestMin = c;
				 	bestRunner = a;
				 }
			}
		}
		
		cout << bestRunner << " " << certif << "\n";
	}
}