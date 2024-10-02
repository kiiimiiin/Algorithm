#include <iostream>
#include <vector>
using namespace std;
const int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

struct Fire {
	int r, c, m, s, d;
};

int n, m, k;

vector<int> tmp[52][52];
vector<Fire> fire;

void ProcessOOB(int& x, int& y) {
	if (x >= n) x = x - n;
	else if (x < 0) x = n + x;
	
	if (y >= n) y = y - n;
	else if (y < 0) y = n + y;
}


void MoveMerge() {
	
	
	for (int idx = 0; idx < fire.size(); idx++) {
		auto f = fire[idx];
		int nx = f.r + (f.s % n) * dx[f.d];
		int ny = f.c + (f.s % n) * dy[f.d];
		ProcessOOB(nx, ny);
		tmp[nx][ny].push_back(idx);
		fire[idx].r = nx;
		fire[idx].c = ny;
	}


	vector<Fire> ftmp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (tmp[i][j].empty()) continue;
			if (tmp[i][j].size() == 1) {
				int idx = tmp[i][j].front();
				ftmp.push_back(fire[idx]);
			}
			else if (tmp[i][j].size() >= 2) {
				int m, s, oddCnt, size;
				m = s = oddCnt = 0; size = tmp[i][j].size();

				for (int idx : tmp[i][j]) {
					auto f = fire[idx];
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
						ftmp.push_back({ i, j, m, s, d });
				}
				else {
					for (int d : {1, 3, 5, 7})
						ftmp.push_back({ i, j, m, s, d });
				}
			}
			tmp[i][j].clear();
		}
	}
	fire = ftmp;
}

int getAns() {
	int ret = 0;
	for (auto f : fire)
		ret += f.m;
	return ret;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	cin >> n >> m >> k;

	for (int i = 0; i < m; i++) {
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		fire.push_back({ r-1, c-1, m, s, d });
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


	1. 구조체 배열 -> 인덱스보드

	move : 구조체 배열을 순회하며 이동, 인덱스보드 업데이트
	merge : 인덱스보드를 순회하며 ( 구조체 배열 순회시 동일자리 인덱스 찾기 어렵)
			merge

*/