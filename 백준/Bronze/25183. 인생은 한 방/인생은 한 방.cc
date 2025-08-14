#include <bits/stdc++.h>

using namespace std;

int main(){
	int N;
	string lotto;
	cin >> N >> lotto;
	
	int cnt = 0;
	for(int i = 1; i < N; i++){
		if(lotto[i - 1] == lotto[i] - 1 or lotto[i - 1] == lotto[i] + 1){
			cnt++;
			if(cnt >= 4){
				cout << "YES";
				return 0;
			}
			continue;
		}
		cnt = 0;
	}
	
	cout << "NO";
	return 0;
}