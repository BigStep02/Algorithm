#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int p1_score = 0, p2_score = 0;
        for (int i = 0; i < n; i++) {
            char p1, p2;
            cin >> p1 >> p2;
            if (p1 == p2) continue;
            if ((p1 == 'R' && p2 == 'S') || (p1 == 'S' && p2 == 'P') || (p1 == 'P' && p2 == 'R')) {
                p1_score++;
            } else {
                p2_score++;
            }
        }

        if (p1_score > p2_score) cout << "Player 1\n";
        else if (p2_score > p1_score) cout << "Player 2\n";
        else cout << "TIE\n";
    }
}