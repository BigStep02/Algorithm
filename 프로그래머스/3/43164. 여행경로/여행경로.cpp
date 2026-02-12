#include <bits/stdc++.h>

using namespace std;

void dfs(string now, vector<string> &answer, map<string, vector<string>> &graph){
    while(!graph[now].empty()){
        string next = graph[now].back();
        
        graph[now].pop_back();
        
        dfs(next, answer, graph);
    }
    answer.push_back(now);
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    map<string, vector<string>> graph;
    
    for(int i = 0; i < tickets.size(); i++){
        graph[tickets[i][0]].push_back(tickets[i][1]);
    }
    
    for(auto &pair : graph){
        sort(pair.second.begin(), pair.second.end(), greater<string>());
    }
    
    dfs("ICN", answer, graph);
    
    reverse(answer.begin(), answer.end());
    
    return answer;
}