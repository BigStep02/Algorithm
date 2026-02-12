#include <string>
#include <vector>

using namespace std;

int dfs(int idx, int calNum, vector<int> &numbers, int target){
    if(idx == numbers.size()){
        return (calNum == target)? 1 : 0;
    }
    
    int plus = dfs(idx + 1, calNum + numbers[idx], numbers, target);
    int minus = dfs(idx + 1, calNum - numbers[idx], numbers, target);
    
    return plus + minus;
}

int solution(vector<int> numbers, int target) {
    
    return dfs(0, 0, numbers, target);
}