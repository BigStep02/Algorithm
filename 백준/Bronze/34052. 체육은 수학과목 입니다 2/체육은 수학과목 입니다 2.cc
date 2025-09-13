#include <bits/stdc++.h>

using namespace std;

int main(){
	int answer = 0;
	for(int i = 0; i < 4; i++){
		int A;
		cin >> A;
		answer += A;
	}
	answer += 300;
	cout << (answer <= 1800? "Yes" : "No");
}