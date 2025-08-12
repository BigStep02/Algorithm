#include <bits/stdc++.h>

using namespace std;

int minNum = 1, maxNum = 10;

void check_num(const int N, const string &word){
	if(word == "too high") maxNum = min(maxNum, N - 1);
	else if(word == "too low") minNum = max(minNum, N + 1);
}

int main(){
	while(true){
		int N;
		cin >> N;
		if(N == 0) break;
		cin.ignore();
		
		string word;
		getline(cin, word);
		
		if(word == "right on"){
			if(N >= minNum and N <= maxNum){
				cout << "Stan may be honest" << "\n";
			}
			else cout << "Stan is dishonest" << "\n";
			minNum = 1, maxNum = 10;
		}
		
		else check_num(N, word);
	}
}