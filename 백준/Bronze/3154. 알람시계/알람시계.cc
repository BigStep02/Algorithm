#include <iostream>
#include <string>
#include <sstream>
#include <utility>
#include <cmath>
#include <vector>

using namespace std;

void effort(int firstNum, int secondNum, const vector<pair<int, int>> &keypad, int &cost){
	cost += abs(keypad[firstNum].first - keypad[secondNum].first) + abs(keypad[firstNum].second - keypad[secondNum].second);
}

int main(){
	string time;
	
	cin >> time;
	
	stringstream ss(time);
	
	string strHour, strMin;
	
	getline(ss, strHour, ':');
	getline(ss, strMin);
	
	int hour = stoi(strHour);
	int min = stoi(strMin);
	
	vector<pair<int, int>> keypad(10);
	keypad[1] = {0, 0};
	keypad[2] = {0, 1};
	keypad[3] = {0, 2};
	keypad[4] = {1, 0};
	keypad[5] = {1, 1};
	keypad[6] = {1, 2};
	keypad[7] = {2, 0};
	keypad[8] = {2, 1};
	keypad[9] = {2, 2};
	keypad[0] = {3, 1};
	
	string answer;
	int minCost = 999999999;
	for(int i = hour; i < 100; i += 24){
		for(int j = min; j < 100; j += 60){
			string hourStr, minStr;
			int cost = 0;
			
			hourStr = to_string(i);
			if (hourStr.size() == 1) hourStr = "0" + hourStr; 
			minStr = to_string(j);
			if (minStr.size() == 1) minStr = "0" + minStr;
			
			effort(hourStr[0] - '0', hourStr[1] - '0', keypad, cost);
			effort(hourStr[1] - '0', minStr[0] - '0', keypad, cost);
			effort(minStr[0] - '0', minStr[1] - '0', keypad, cost);
			
			if(cost < minCost){
				minCost = cost;
				answer = hourStr + ":" + minStr;
			}
		}
	}
	
	cout << answer << endl;
	
	return 0;
}