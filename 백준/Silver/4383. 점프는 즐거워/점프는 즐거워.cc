#include <iostream>
#include <set>
using namespace std;

int N;
int arr[3000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> N) {
		bool chk = 1;
		set<int> st;
		for (int i = 0; i < N; i++) cin >> arr[i];
		for (int i = 1; i < N; i++) {
			int diff = abs(arr[i] - arr[i - 1]);
			if (0 < diff && diff < N) st.insert(diff);
		}

		if (st.size() == N - 1) cout << "Jolly\n";
		else cout << "Not jolly\n";
	}
}