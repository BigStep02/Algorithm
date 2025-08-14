#include <bits/stdc++.h>

using namespace std;

void swap(int &A, int &B){
	int tmp;
	
	tmp = A;
	A = B;
	B = tmp;
}

int main(){
	long long A, B;
	cin >> A >> B;
	
	if(A == B){
		cout << 0;
		return 0;
	}
	if(A > B){
		swap(B, A);
	}
	cout << B - A - 1 << endl;
	for(long long i = A + 1; i < B; i++){
		cout << i << " ";
	}
}