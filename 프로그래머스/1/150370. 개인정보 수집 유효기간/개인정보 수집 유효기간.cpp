#include <bits/stdc++.h>

using namespace std;

void check_destroyed(string &today, const vector<int> &due_date, vector<int> &answer){
	today.erase(remove(today.begin(), today.end(), '.'), today.end());
	int day = stoi(today);
	
	for(int i = 0; i < due_date.size(); i++){
		if(due_date[i] < day) answer.push_back(i + 1);
	}
}

void change_due_date(vector<int> &due_date, int termMonths, string privacies, int num){
	int year  = stoi(privacies.substr(0, 4));
	int month = stoi(privacies.substr(5, 2));
	int day   = stoi(privacies.substr(8, 2)) - 1;
	
	month += termMonths;
	
	if (day <= 0){
		day = 28;
		month--;
	}
	
	while (month > 12) {
	    month -= 12;
	    year++;
	}
	while (month <= 0) {
	    month += 12;
	    year--;
	}
	
	string strYear, strMonth, strDay;
	
	strYear = to_string(year);
	strMonth = to_string(month);
	if(strMonth.size() == 1) strMonth = "0" + strMonth;
	strDay = to_string(day);
	if(strDay.size() == 1) strDay = "0" + strDay;
	
	int date = stoi(strYear + strMonth + strDay);
	
	due_date[num] = date;
}

void check_due_date(const vector<string> &terms, vector<int> &due_date, const vector<string> &privacies){
	for(int i = 0; i < terms.size(); i++){
		int termMonths = stoi(terms[i].substr(2));
		for(int j = 0; j < privacies.size(); j++){
			if(terms[i][0] == privacies[j][privacies[j].size() - 1]) change_due_date(due_date, termMonths, privacies[j], j);
		}
	}
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    vector<int> due_date(privacies.size());
    check_due_date(terms, due_date, privacies);
    
    check_destroyed(today, due_date, answer);
    
    return answer;
}
