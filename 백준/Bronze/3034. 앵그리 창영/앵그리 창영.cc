#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, W, H;
    cin >> N >> W >> H;

    int max_len_sq = W * W + H * H;

    for (int i = 0; i < N; i++) {
        int match;
        cin >> match;

        if (match * match <= max_len_sq) {
            cout << "DA" << "\n";
        } else {
            cout << "NE" << "\n";
        }
    }
}