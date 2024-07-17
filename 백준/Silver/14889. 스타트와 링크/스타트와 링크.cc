#include <iostream>
#include <math.h>
using namespace std;
int s[22][22];
bool candi[22];
int n;
int mn = 0x7f7f7f7f;

void dfs(int k, int st) {
	if (k == n / 2) {
		int sum1, sum2, idx1, idx2;
		int team1[11], team2[11];
		
		sum1 = sum2 = idx1 = idx2 = 0;
		

		for (int i = 0; i < n; i++) {
			if (candi[i]) team1[idx1++] = i;
			else team2[idx2++] = i;
		}

			
		for (int i = 0; i < n / 2; i++) {
			for (int j = i + 1; j < n / 2; j++) {
				sum1 += s[team1[i]][team1[j]] + s[team1[j]][team1[i]];
				sum2 += s[team2[i]][team2[j]] + s[team2[j]][team2[i]];
			}
		}

		mn = min(mn, abs(sum1 - sum2));
		return;
	}

	for (int i = st; i < n; i++) {
		candi[i] = true;
		dfs(k + 1, i + 1);
		candi[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n; 

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> s[i][j];
		}
	}

	dfs(0, 0);
	cout << mn;
}