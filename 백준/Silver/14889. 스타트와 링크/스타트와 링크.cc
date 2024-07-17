#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
int s[22][22];
int t1[11], t2[11];
int n;
int mn = 0x7f7f7f7f;


int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n; 

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> s[i][j];
		}
	}

	vector<int> candi;
	for (int i = 0; i < n; i++) {
		if (i < n / 2) candi.push_back(0);
		else candi.push_back(1);
	}

	do {
		int idx1, idx2, sum1, sum2;
		sum1 = sum2 = idx1 = idx2 = 0;

		for (int i = 0; i < n; i++) {
			if (candi[i] == 0) t1[idx1++] = i;
			else t2[idx2++] = i;
		}

		for (int i = 0; i < n / 2; i++) {
			for (int j = i + 1; j < n / 2; j++) {
				sum1 += s[t1[i]][t1[j]] + s[t1[j]][t1[i]];
				sum2 += s[t2[i]][t2[j]] + s[t2[j]][t2[i]];
			}
		}

		mn = min(mn, abs(sum1 - sum2));
	} while (next_permutation(candi.begin(), candi.end()));

	cout << mn; 
}