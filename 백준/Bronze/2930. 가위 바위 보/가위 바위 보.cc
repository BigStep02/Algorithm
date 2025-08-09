#include <iostream>
#include <string>
#include <vector>

using namespace std;

int RCP(char sang, char fri){
	if(sang == fri) return 1;
	
	if(sang == 'R'){
		if(fri == 'P') return 0;
		else return 2;
	}
	else if(sang == 'S'){
		if(fri == 'R') return 0;
		else return 2;
	}
	else{
		if (fri == 'S') return 0;
		else return 2;
	}
}

int main(){
	int R, N;
	
	cin >> R;
	
	string sanggeun;
	
	cin >> sanggeun;
	
	cin >> N;
	
	vector<string> friends;
	
	for(int i = 0; i < N; i++){
		string tmp;
		cin >> tmp;
		friends.push_back(tmp);
	}
	
	int nowCnt = 0;	
	for(int i = 0; i < sanggeun.size(); i++){
		for(int j = 0; j < friends.size(); j++){
			for(int k = i; k <= i; k++){
				nowCnt += RCP(sanggeun[i], friends[j][k]);
			}
		}
	}
	
	int maxCnt = 0;
	vector<char> sangRCP{'R', 'S', 'P'};
	
	for(int i = 0; i < R; i++){
		int checkMax = 0;
		for(int j = 0; j < sangRCP.size(); j++){
			int check = 0;
			for(int k = 0; k < friends.size(); k++){
				check += RCP(sangRCP[j], friends[k][i]);
			}
			if (checkMax < check) checkMax = check;
		}
		maxCnt += checkMax;
	}
	
	cout << nowCnt << "\n" << maxCnt;
	
	return 0;
}