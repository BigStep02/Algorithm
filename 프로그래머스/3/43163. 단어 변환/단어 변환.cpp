#include <string>
#include <vector>

using namespace std;

vector<bool> used;

bool check(string word1, string word2){
    int cnt = 0;
    for(int i = 0; i < word1.size(); i++){
        if(word1[i] != word2[i]) cnt++;
    }
    
    return (cnt == 1)? true : false;
}

void dfs(string current, int cnt, int &answer, string begin, string target, vector<string> &words){
    if(current == target){
        answer = min(answer, cnt);
        return;
    }
    
    for(int i = 0; i < words.size(); i++){
        if(used[i]) continue;
        if(!check(words[i], current)) continue;
        used[i] = true;
        dfs(words[i], cnt + 1, answer, words[i], target, words);
        used[i] = false;
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 1e9;
    used.resize(words.size(), false);
    
    dfs(begin, 0, answer, begin, target, words);
    
    return (answer != 1e9) ? answer : 0;
}