#include <bits/stdc++.h>

using namespace std;

void make_friendNum(const vector<string> &friends, unordered_map<string, int> &friendNum){
	for(int i = 0; i < friends.size(); i++){
		friendNum.insert({friends[i], i});
	}
}

void make_giveGiftCount_giftValue(const unordered_map<string, int> &friendNum, vector<vector<int>> &giveGiftCount, vector<int> &giftValue, const vector<string> &gifts){
	for(int i = 0; i < gifts.size(); i++){
		string tmp = gifts[i];
		
		stringstream ss(tmp);
		string firstFriend, secondFriend;
		
		ss >> firstFriend >> secondFriend;
		
		int firstFriendIdx = friendNum.at(firstFriend), secondFriendIdx = friendNum.at(secondFriend);
		
		giveGiftCount[firstFriendIdx][secondFriendIdx]++;
		giftValue[firstFriendIdx]++;
		giftValue[secondFriendIdx]--;
	}
}

void check_receive(const vector<int> &giftValue, vector<int> &receiveGiftCount, int firstFriend, int secondFriend){
	if (giftValue[firstFriend] == giftValue[secondFriend]) return;
	(giftValue[firstFriend] > giftValue[secondFriend])? receiveGiftCount[firstFriend]++ : receiveGiftCount[secondFriend]++;
}

int check_answer(const vector<vector<int>> &giveGiftCount, const vector<int> &giftValue, const vector<string> &friends){
	vector<int> receiveGiftCount(friends.size());
	
	for(int i = 0; i < friends.size(); i++){
		for(int j = i + 1; j < friends.size(); j++){
			if (giveGiftCount[i][j] == giveGiftCount[j][i]){
				check_receive(giftValue, receiveGiftCount, i, j);
				continue;
			}
			(giveGiftCount[i][j] > giveGiftCount[j][i])? receiveGiftCount[i]++ : receiveGiftCount[j]++;
		}
	}
	
	return *max_element(receiveGiftCount.begin(), receiveGiftCount.end());
}

int solution(vector<string> friends, vector<string> gifts) {
    unordered_map<string, int> friendNum;
    make_friendNum(friends, friendNum);
    
    vector<vector<int>> giveGiftCount(friends.size(), vector<int>(friends.size(), 0));
    vector<int> giftValue(friends.size());
    make_giveGiftCount_giftValue(friendNum, giveGiftCount, giftValue, gifts);

    return check_answer(giveGiftCount, giftValue, friends);
}
