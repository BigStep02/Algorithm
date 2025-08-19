#include <bits/stdc++.h>

using namespace std;

int main(){
	int N;
	cin >> N;
	cin.ignore();
	for(int i = 1; i <= N; i++){
		string S;
		getline(cin, S);
		cout << i << ". " << S << "\n";
	}
}