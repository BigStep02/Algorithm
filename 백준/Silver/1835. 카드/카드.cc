#include <iostream>
#include <deque>

using namespace std;

int main(){
	int N;
	
	cin >> N;
	
	deque<int> deque;

	for (int i = N; i > 0; i--){
		deque.push_back(i);
		for (int j = 0; j < i; j++){
			int tmp = deque.front();
			deque.pop_front();
			deque.push_back(tmp);
		}
	}
	
	for (int i = 0; i < N; i++){
		int tmp = deque.back();
		deque.pop_back();
		cout << tmp << " ";
	}
	
	return 0;
}