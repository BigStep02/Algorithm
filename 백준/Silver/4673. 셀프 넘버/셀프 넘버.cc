#include <bits/stdc++.h>

using namespace std;

int main(){
	vector<int> nums(10100, 0);
	
	for(int i = 1; i < 10000; i++){
		string s = to_string(i);
		int temp = i;
		for(int j = 0; j < s.size(); j++){
			temp += s[j] - '0';
		}
		nums[temp]++;
	}
	
	for(int i = 1; i < 10001; i++){
		if(nums[i] == 0) cout << i << "\n";
	}
}