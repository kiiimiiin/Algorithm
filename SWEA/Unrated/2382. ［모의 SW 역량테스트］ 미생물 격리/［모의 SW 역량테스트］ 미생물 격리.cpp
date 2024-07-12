#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
#include <stdio.h>

using namespace std;

struct Virsu {
	int x, y, num, dir;
};
const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 }; // 상하좌우
vector<int> board[102][102]; // 바이러스 인덱스 보드
Virsu virus[1002];
int n, m, k;

void Init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!board[i][j].empty())
				board[i][j].clear();
		}
	}
	for (int i = 0; i < k; i++) virus[i] = { 0, 0, 0, 0 };
}


int Solve() {
	cin >> n >> m >> k;
	Init();

	for (int i = 0; i < k; i++) {
		int x, y, num, dir;
		cin >> x >> y >> num >> dir;
		virus[i] = { x, y, num, dir - 1 };
		board[x][y].push_back(i);
	}

	while (m--) {
		// 군집 이동  
		for (int i = 0; i < k; i++) {
			if (virus[i].num == 0) continue;

			board[virus[i].x][virus[i].y].pop_back();
			int nx = virus[i].x + dx[virus[i].dir];
			int ny = virus[i].y + dy[virus[i].dir];
			int nd = virus[i].dir;
			int nn = virus[i].num;
			if (nx <= 0 || nx >= n - 1 || ny <= 0 || ny >= n - 1) { // 가장자리
				nn = virus[i].num / 2;
				nd = virus[i].dir % 2 ? virus[i].dir - 1 : virus[i].dir + 1;
			}
			virus[i] = { nx, ny, nn, nd };
		}

		for (int i = 0; i < k; i++) {
			if (virus[i].num == 0) continue;
			board[virus[i].x][virus[i].y].push_back(i);
		}


		// 군집 합체
		for (int i = 0; i < k; i++) {
			if (virus[i].num == 0) continue;
			auto v = virus[i];
			if (board[v.x][v.y].size() >= 2) {
				int mxNum = -0x7f7f7f7f;
				int mxDir = -1;
				int mxIdx = -1;
				int sum = 0;
				for (int vi : board[v.x][v.y]) {
					if (mxNum < virus[vi].num) {
						mxNum = virus[vi].num;
						mxDir = virus[vi].dir;
						mxIdx = vi;
					}
					sum += virus[vi].num;
					virus[vi].num = 0;
				}
				virus[mxIdx] = { v.x, v.y, sum, mxDir };
				board[v.x][v.y].clear();
				board[v.x][v.y].push_back(mxIdx);
			}
		}
	}

	// 남아 있는 미생물 총합
	int ret = 0;
	for (int i = 0; i < k; i++) {
		if (virus[i].num == 0) continue;
		ret += virus[i].num;
	}
	return ret;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("sample_input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int ans = Solve();
		cout << "#" << test_case << " " << ans << '\n';
	}
	return 0;
}