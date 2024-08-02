#include <algorithm>
#include <iostream>
#include <vector>
#define X first
#define Y second
using namespace std;
const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };
int n, m, k;
int board[22][22];
int table[402][4][4];
pair<int, int> smell[22][22];

struct Shark {
	int x, y, dir;
	bool isLive; 
};

Shark sharks[402];

bool OOB(int x, int y) {
	return x < 0 || x >= n || y < 0 || y >= n; 
}

void doSmell() {

	for (int i = 0; i < n; i++) { // 냄새 시간 감소
		for (int j = 0; j < n; j++) {
			if (smell[i][j].Y > 0)
				smell[i][j].Y--;
			
			if (smell[i][j].Y == 0)
				smell[i][j].X = 0; 
		}
	}

	for (int i = 1; i <= m; i++) { // 상어 위치에 냄새 추가
		if (!sharks[i].isLive) continue;
		smell[sharks[i].x][sharks[i].y] = { i, k };
	}
}


void move() {
	for (int i = m; i > 0; i--) {
		if (!sharks[i].isLive) continue;
		
		bool toClean = false;
		for (int dir = 0; dir < 4; dir++) { // 아무 냄새 없는 칸
			int nd = table[i][sharks[i].dir][dir];
			int nx = sharks[i].x + dx[nd];
			int ny = sharks[i].y + dy[nd];
			if (OOB(nx, ny)) continue;
			if (smell[nx][ny].Y == 0) {
				if (board[nx][ny] > 0) // 상어를 만나 eat
					sharks[board[nx][ny]].isLive = false;

				board[sharks[i].x][sharks[i].y] = 0;
				board[nx][ny] = i;

				sharks[i].dir = nd;
				sharks[i].x = nx;
				sharks[i].y = ny;
				
				toClean = true;
				break; 
			}
		}
		
		if (toClean) continue;

		for (int dir = 0; dir < 4; dir++) { // 냄새 있는 칸
			int nd = table[i][sharks[i].dir][dir];
			int nx = sharks[i].x + dx[nd];
			int ny = sharks[i].y + dy[nd];
			if (OOB(nx, ny)) continue;
			if (smell[nx][ny].X == i && smell[nx][ny].Y > 0) {
				board[sharks[i].x][sharks[i].y] = 0;
				board[nx][ny] = i;

				sharks[i].dir = nd;
				sharks[i].x = nx;
				sharks[i].y = ny;
				break;
			}
		}
		
	}
}

bool existOnlyOne() {
	for (int i = 2; i <= m; i++) {
		if (sharks[i].isLive) return false;
	}

	return true;
}


int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	cin >> n >> m >> k;
	

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] > 0) {
				sharks[board[i][j]] = { i, j, -1, true };
			}
		}
	}

	for (int i = 1; i <= m; i++) {
		int fdir;
		cin >> fdir;
		fdir--;
		sharks[i].dir = fdir;
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				int dir;
				cin >> dir; 
				dir--;
				table[i][j][k] = dir; 
			}
		}
	}


	int t = 0;

	doSmell();
	while (1) {
		if (existOnlyOne()|| t > 1000)
			break;
		move();
		doSmell();
		t++;
	}

	cout << (t > 1000 ? -1 : t);
}

/* 
	상어가 냄새를 뿌림 -> 인접칸 중 하나로 이동 -> 상어의 섭취

	이동방향 결정
	아무 냄새가 없는 칸 > 없으면 자신의 냄새가 있는 칸 
	( 가능한 칸이 여러개 일 시 상어 우선순위를 따름 ) 	
*/