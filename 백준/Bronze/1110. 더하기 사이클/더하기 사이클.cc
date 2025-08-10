#include <bits/stdc++.h>

using namespace std;

int main(){
	int N, idx = 0;
	cin >> N;
	
	int tmp = N;
	
	while (true){
		idx++;
		
		N = ((N % 10) * 10) + (((N / 10) + (N % 10)) % 10);

		if(tmp == N){
			cout << idx << endl;
			break;
		}
	}
}