#include <bits/stdc++.h>

using namespace std;

int main(){
	int cnt = 0, idx = 1;
	
	while(true){
		vector<string> words(2);
		
		for(int i = 0; i < 2; i++){
			cin >> words[i];
			if (words[i] == "END") cnt++;
			if (cnt >= 2) return 0;
		}
		char ch1[words[0].size() + 1];
		strcpy(ch1, words[0].c_str());
		sort(ch1, ch1 + words[0].size());
		
		char ch2[words[1].size() + 1];
		strcpy(ch2, words[1].c_str());
		sort(ch2, ch2 + words[1].size());
		
		string str1(ch1);
		string str2(ch2);
		
		if (str1 == str2){
			cout << "Case " << idx << ": " << "same" << endl;
		}
		else cout << "Case " << idx << ": " << "different" << endl;
		
		idx++;
	}
}