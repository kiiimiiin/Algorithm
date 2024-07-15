#include <iostream>
#include <algorithm>
using namespace std;
int arr[12];
int op[4];
int n;
int mx = -0x7f7f7f7f; 
int mn = 0x7f7f7f7f;

void dfs(int k, int res) {
	if (k == n - 1) {
		mx = max(mx, res);
		mn = min(mn, res);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (op[i] <= 0) continue;
		op[i]--;

		if (i == 0)
			dfs(k + 1, res + arr[k + 1]);
		else if (i == 1)
			dfs(k + 1, res - arr[k + 1]);
		else if (i == 2) 
			dfs(k + 1, res * arr[k + 1]);
		else if (i == 3)
			dfs(k + 1, res / arr[k + 1]);

		op[i]++;
	}
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) cin >> arr[i];


	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}

	dfs(0, arr[0]);
	cout << mx << '\n' << mn;
}