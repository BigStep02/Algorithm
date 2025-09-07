#include <bits/stdc++.h>

using namespace std;

int main(){
	int A, B, answer = 0, cnt = 1, cntCheck = 0;
	cin >> A >> B;
	vector<int> nums(1002);
	
	for(int i = 1; i < 1001; i++){
		nums[i] = cnt;
		cntCheck++;
		if(cnt == cntCheck){
			cnt++;
			cntCheck = 0;
		}
	}
	
	for(int i = A; i <= B; i++){
		answer += nums[i];
	}
	
	cout << answer;
}