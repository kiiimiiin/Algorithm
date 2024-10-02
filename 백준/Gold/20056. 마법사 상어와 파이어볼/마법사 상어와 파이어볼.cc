#include <iostream>
#include <vector>
using namespace std;
const int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

struct Fire {
	int m, s, d;
};

int n, m, k;

vector<Fire> board[52][52];
vector<Fire> tmp[52][52];

void ProcessOOB(int& x, int& y) {
	if (x >= n) x = x - n;
	else if (x < 0) x = n + x;

	if (y >= n) y = y - n;
	else if (y < 0) y = n + y;
}

void MoveMerge() {
	

	// 1. move
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j].empty()) continue;
			for (auto f : board[i][j]) {
				int nx = i + (f.s % n) * dx[f.d];
				int ny = j + (f.s % n) * dy[f.d];
				ProcessOOB(nx, ny);
				tmp[nx][ny].push_back(f);
			}
			board[i][j].clear();
		}
	}

	// 2. merge
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (tmp[i][j].empty()) continue;
			if (tmp[i][j].size() == 1)
				board[i][j].push_back(tmp[i][j].front());
			else {
				int m, s, size, oddCnt;
				m = s = oddCnt = 0; size = tmp[i][j].size();
				for (auto f : tmp[i][j]) {
					m += f.m;
					s += f.s;
					oddCnt += f.d % 2;
				}
				m /= 5; s /= size;
				if (m <= 0) {
					tmp[i][j].clear();
					continue;
				}

				if (oddCnt == size || oddCnt == 0) {
					for (int d : {0, 2, 4, 6})
						board[i][j].push_back({ m, s, d });
				}
				else {
					for (int d : {1, 3, 5, 7})
						board[i][j].push_back({ m, s, d });
				}
			}
			tmp[i][j].clear();
		}
		
	}
}

int getAns() {
	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j].empty()) continue;
			for (auto f : board[i][j])
				ret += f.m;
		}
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	cin >> n >> m >> k;

	for (int i = 0; i < m; i++) {
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		board[r - 1][c - 1].push_back({ m, s, d });
	}

	int ans = 0;
	while (k--) {
		MoveMerge();
	}

	ans = getAns();
	cout << ans;
}

/*

	격자 연결

	이동 -> 결합

	구조체 벡터 보드


*/