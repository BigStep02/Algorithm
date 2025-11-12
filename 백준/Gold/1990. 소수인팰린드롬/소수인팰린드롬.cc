#include <bits/stdc++.h>

using namespace std;

bool is_palin(int x){
    string S = to_string(x);

    for(int i = 0; i < S.size() / 2; i++){
        if (S[i] != S[S.size() - 1 - i]){
            return false;
        }
    }
    return true;
}

void eratos(vector<bool> &prime, int B){
    for(int i = 2; i * i <= B; i++){
        if(prime[i] == false) continue;
        for(int j = i * 2; j < prime.size(); j += i){
            prime[j] = false;
        }
    }
}

int main(){
    int A, B;
    cin >> A >> B;
    vector<bool> prime(B + 1, true);

    eratos(prime, B);

    for(int i = A; i < prime.size(); i++){
        if(prime[i] == true){
            if(is_palin(i)){
                cout << i << "\n";
            }
        }
    }
    cout << -1 << endl;
}