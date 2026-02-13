#include <bits/stdc++.h>

using namespace std;

bool check(int min1, int max1, vector<vector<int>> &sizes){
    for(const auto &size : sizes){
        if((min1 < size[0] or max1 < size[1]) and (max1 < size[0] or min1 < size[1])) return false;
    }
    
    return true;
}

int solution(vector<vector<int>> sizes) {
    int answer = 1e9;
    
    int min1 = 1e9, max1 = 0;
    
    for(const auto &size : sizes){
        min1 = min({min1, size[0], size[1]});
        max1 = max({max1, size[0], size[1]});
    }
    
    for(int i = min1; i <= max1; i++){
        for(int j = min1; j <= max1; j++){
            if(check(i, j, sizes)){
                answer = min(answer, i * j);
            }
        }
    }
    
    return answer;
}