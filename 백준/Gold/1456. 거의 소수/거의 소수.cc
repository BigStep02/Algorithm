#include <bits/stdc++.h>

#define MAX_VALUE	10000000

using namespace std;\

void eratos(vector<bool> &primes){
	
	for(int i = 2; i * i <= MAX_VALUE; i++){
		if(primes[i] == false) continue;
		for(long long j = (long long)i * i; j <= MAX_VALUE; j += i){
			primes[j] = false;
		}
	}
}

void almost_prime(vector<bool> &primes, set<long long> &answer, long long A, long long B){
	for(int i = 2; i * i <= B; i++){
		if(primes[i] == false) continue;
		
		long long power = (long long) i * i;
		if(power > B) break;
		
		while(true){
			if(power >= A) answer.insert(power);
			
			if(power > B / i) break;
			
			power *= i;
			
			if(power > B) break;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	
	long long A, B;
	int cnt = 0;
	cin >> A >> B;
	
	vector<bool> primes(MAX_VALUE + 1, true);
	set<long long> answer;
	eratos(primes);
	almost_prime(primes, answer, A, B);
	
	cout << answer.size();
}