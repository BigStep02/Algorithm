#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; 
    cin >> N;

    int give = 0;

    if (N >= 1000000) {
        give = N * 20 / 100;
    }
    else if (N >= 500000) {
        give = N * 15 / 100;
    }
    else if (N >= 100000) {
        give = N * 10 / 100;
    }
    else {
        give = N * 5 / 100;
    }

    int keep = N - give;
    cout << give << " " << keep << "\n";
}
