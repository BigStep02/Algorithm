#include <bits/stdc++.h>

using namespace std;

int main(){
	int T;
	cin >> T;
	
	for(int i = 0; i < T; i++){
		int maxWeight, area, distance = 0, nowWeight = 0, nowDistance = 0;
		
		cin >> maxWeight >> area;
		
		for(int j = 0; j < area; j++){
			int A, B;
			cin >> A >> B;
			
			distance += A - nowDistance;
			nowDistance = A;
			
			nowWeight += B;
			
			if(nowWeight > maxWeight){
				distance += A * 2;
				nowWeight = B;
			}
						
			if(nowWeight == maxWeight){
				distance += A;
				nowWeight = 0;
				nowDistance = 0;
			}
		}
		cout << distance + nowDistance << endl;
	}
}