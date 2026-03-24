#include <bits/stdc++.h>

using namespace std;

deque<string> dq;
string func, S;
int N;

int main(){
  int tc; cin >> tc;

  while(tc--){
    cin >> func >> N >> S;
    S = S.substr(1, S.length() - 2);

    dq.clear();

    stringstream ss(S);
    string temp;
    while(getline(ss, temp, ',')){
      dq.push_back(temp);
    }

    bool isStart = true;
    bool first = true;
    string ans = "";

    ans += "[";

    for(int i = 0; i < func.size(); i++){
      if(func[i] == 'R'){
        isStart = !isStart;
      }
      else{
        if(dq.empty()) { ans = "error"; break;}
        if(isStart) { dq.pop_front(); }
        else { dq.pop_back(); }
      }
    }

    if(ans == "error") { cout << ans << '\n'; continue;}

    while(!dq.empty()){
      if(!first) ans += ",";
      if(isStart) { ans += dq.front(); dq.pop_front();}
      else { ans += dq.back(); dq.pop_back();}
      first = false;
    }

    cout << ans << "]" << "\n";
  }
}