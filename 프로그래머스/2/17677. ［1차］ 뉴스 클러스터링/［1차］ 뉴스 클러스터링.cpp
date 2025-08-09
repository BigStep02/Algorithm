#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void change_lower(string &str1, string &str2){
	for (int i = 0; i < str1.size(); i++){
		str1[i] = tolower(str1[i]);
	}
	
	for (int i = 0; i < str2.size(); i++){
		str2[i] = tolower(str2[i]);
	}
}

void change_multiset(vector<string> &firstMultiset, vector<string> &secondMultiset, const string &str1, const string &str2){
	
	for (int i = 0; i < str1.size() - 1; i++){
		if (str1[i] < 'a' || str1[i] > 'z' || str1[i + 1] < 'a' || str1[i + 1] > 'z') continue;
		string tmp = string(1, str1[i]) + str1[i + 1];
		firstMultiset.push_back(tmp);
	}
	
	for (int i = 0; i < str2.size() - 1; i++){
		if (str2[i] < 'a' || str2[i] > 'z' || str2[i + 1] < 'a' || str2[i + 1] > 'z') continue;
		string tmp = string(1, str2[i]) + str2[i + 1];
		secondMultiset.push_back(tmp);
	}
}

int find_answer(const vector<string> &wordIntersection, const vector<string> &wordUnion){
	int answer = 0;
	
	if (wordIntersection.size() != 0 && wordUnion.size() != 0){
		double similarity = (static_cast<double>(wordIntersection.size()) / static_cast<double>(wordUnion.size())) * 65536;

		answer = static_cast<int>(similarity);
    
    	return answer;
	}
	else if (wordIntersection.size() != 0 || wordUnion.size() != 0){
		return 0;
	}
	else return 65536;
}

int solution(string str1, string str2) {
    vector<string> firstMultiset;
    vector<string> secondMultiset;
    
    change_lower(str1, str2);
    change_multiset(firstMultiset, secondMultiset, str1, str2);
	
	vector<string> wordIntersection;
	vector<string> wordUnion;
	
	sort(firstMultiset.begin(), firstMultiset.end());
	sort(secondMultiset.begin(), secondMultiset.end());
	
	set_intersection(firstMultiset.begin(), firstMultiset.end(), secondMultiset.begin(), secondMultiset.end(), back_inserter(wordIntersection));
	set_union(firstMultiset.begin(), firstMultiset.end(), secondMultiset.begin(), secondMultiset.end(), back_inserter(wordUnion));
		
	return find_answer(wordIntersection, wordUnion);
}