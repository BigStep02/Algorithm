#include <bits/stdc++.h>

using namespace std;

int main(){
	int N;
	string word;
	cin >> N >> word;
	if(N == 1 or N == 3){
		if(N == 3) word[0] = tolower(word[0]);
		cout << word << "\n";
		string tmp = word;
		for(int i = word.size(); i > 0; i--){
			if('A' <= word[i] and word[i] <= 'Z') {
				word[i] = tolower(word[i]);
				word.insert(i, "_");
			}
		}
		tmp[0] = toupper(tmp[0]);
		
		cout << word << "\n" << tmp;
	}
	
	else if (N == 2) {
		string tmp = word;
		for(int i = 0; i < word.size(); i++){
		if(word[i] == '_') word[i + 1] = toupper(word[i + 1]);
		}
	
		word.erase(remove(word.begin(), word.end(), '_'), word.end());
		cout << word << "\n" << tmp << "\n";
		
		word[0] = toupper(word[0]);
		cout << word;
	}
} 