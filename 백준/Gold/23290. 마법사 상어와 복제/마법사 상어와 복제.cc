#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
#include <algorithm>
#define X first
#define Y second
using namespace std; 
int smell[5][5];
int dx[8] = { 0,-1,-1,-1,0,1,1,1 };
int dy[8] = { -1,-1,0,1,1,1, 0,-1 };
int sdx[4] = { -1,0,1,0 }; // 상좌하우
int sdy[4] = { 0,-1,0,1 };
int m, s; // 물고기수, 연습횟수
int sx, sy;

vector<int> fishes[5][5]; // 물고기 위치와 그에 해당하는 물고기들의 방향들

void TestShark() {
	cout << '\n';
	for (int x = 1; x <= 4; x++) {
		for (int y = 1; y <= 4; y++) {
			if (x == sx && y == sy) {
				cout << 9 << ' ';
			}
			else
				cout << 0 << ' ';
		}
		cout << '\n';
	}
}

void TestFish() {
	cout << '\n';
	for (int x = 1; x <= 4; x++) {
		for (int y = 1; y <= 4; y++) {
			if (!fishes[x][y].empty()) {
				cout << fishes[x][y].front() << ' ';
			}
			else
				cout << 0 << ' ';
		}
		cout << '\n';
	}
}

void TestSmell() {
	cout << '\n';
	for (int x = 1; x <= 4; x++) {
		for (int y = 1; y <= 4; y++) {
			cout << smell[x][y] << ' ';
		}
		cout << '\n';
	}
}

void Input() {
	cin >> m >> s;
	while (m--) {
		int fx, fy, d;
		cin >> fx >> fy >> d;
		
		fishes[fx][fy].push_back(d - 1);
	}
	cin >> sx >> sy; 
}

bool OOB(int x, int y) {
	return x < 1 || x > 4 || y < 1 || y > 4;
}

void Movefish() {
	vector<int> tmp[5][5];

	for (int x = 1; x <= 4; x++) {
		for (int y = 1; y <= 4; y++) {
			if (fishes[x][y].empty()) continue;
			for (int i = 0; i < fishes[x][y].size(); i++) {
				int d = fishes[x][y][i]; 
				int nx = x + dx[d];
				int ny = y + dy[d];
				int cnt = 8;
				while (cnt--) {
					if (OOB(nx, ny) || (nx == sx && ny == sy)
						|| smell[nx][ny]) {
						d = (d + 7) % 8;
						nx = x + dx[d];
						ny = y + dy[d];
						continue;
					}
					else
						break;
				}
				if (cnt >= 0)
					tmp[nx][ny].push_back(d);
				else
					tmp[x][y].push_back(d);
			}
		}
	}

	for (int x = 1; x <= 4; x++) {
		for (int y = 1; y <= 4; y++) {
			fishes[x][y] = tmp[x][y];
		}
	}

}

void MoveShark() {
	vector<pair<int, int>> cseByEatten;
	for (int cse = 0; cse < 64; cse++) {
		int tmp = cse;
		int cnt = 3;
		int eattenFish = 0;
		int is_skipped = 0;
		int dirInfos = 0;
		int nx = sx;
		int ny = sy;
		int vis[5][5] = {}; 
		while (cnt--) {
			int dir = tmp % 4;
			if (cnt == 2) dirInfos += dir * 100;
			if (cnt == 1) dirInfos += dir * 10;
			if (cnt == 0) dirInfos += dir * 1;
			tmp = tmp / 4;
			nx = nx + sdx[dir];
			ny = ny + sdy[dir];
			if (OOB(nx, ny)) { is_skipped = 1; break; }
			if(!vis[nx][ny])
				eattenFish += fishes[nx][ny].size();
			vis[nx][ny] = 1;
		}
		if (is_skipped) continue;
		cseByEatten.push_back({ eattenFish, dirInfos });
		
	}
	sort(cseByEatten.begin(), cseByEatten.end());
	int mxEattenNum = cseByEatten.back().first;
	int mxDirInfos = -1;
	for (auto c : cseByEatten){
		if (c.first == mxEattenNum) {
			mxDirInfos = c.second;
			break;
		}
	}	

	int cnt = 3;
	vector<int> dirsByReversed;
	while (cnt--) {
		int dir = mxDirInfos % 10;
		mxDirInfos = mxDirInfos / 10;
		dirsByReversed.push_back(dir);
	}

	int nx = sx;
	int ny = sy;
	for (int i = 2; i >= 0; i--) {
		int dir = dirsByReversed[i];
		nx = nx + sdx[dir];
		ny = ny + sdy[dir];
		if (!fishes[nx][ny].empty()) {
			fishes[nx][ny].clear();
			smell[nx][ny] = 3;
		}
	}
	
	sx = nx; sy = ny;



}

void EraseSmell() {
	for (int x = 1; x <= 4; x++) {
		for (int y = 1; y <= 4; y++) {
			if (smell[x][y]) smell[x][y]--;
		}
	}
}



void Magic() {
	vector<int> copyFishes[5][5]; // 1. 상어 복제

	for (int x = 1; x <= 4; x++) {
		for (int y = 1; y <= 4; y++) {
			copyFishes[x][y] = fishes[x][y];
		}
	}

	Movefish();
	MoveShark();
	EraseSmell();

	for (int x = 1; x <= 4; x++) { // 5. 상어 복제 완료
		for (int y = 1; y <= 4; y++) {
			if (copyFishes[x][y].empty()) continue;
			for (auto cf : copyFishes[x][y])
				fishes[x][y].push_back(cf);
		}
	}
}
void Solve() {

	while (s--) {
		Magic(); 
	}

	


	int ans = 0;
	for (int x = 1; x <= 4; x++) {
		for (int y = 1; y <= 4; y++) {
			if (fishes[x][y].empty()) continue;
			ans += fishes[x][y].size();
		}
	}
	cout << ans;
}
int main(void) {
	ios::sync_with_stdio(false), cin.tie(0);

	Input();
	Solve();
}