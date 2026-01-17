#include <iostream>
#include <utility>
using namespace std;
int n, m, k;
int board[21][21];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0, 0, -1,1 };
pair<int, int> smell[21][21];


struct Shark {
	int x, y, dir; 
	int table[4][4];
	int isLived = false;
};

Shark shark[401];

bool IsOnlyOneShark() {
	for (int idx = 2; idx <= m; idx++) {
		if (shark[idx].isLived == true) return false;
	}
	if (shark[1].isLived == true) {
		return true;
	}
	else {
		cout << "Is Error\n";
		return false;
	}
}

void MoveShark() {
	for (int idx = 1; idx <= m; idx++) {
		if (shark[idx].isLived == false) continue;
		
		bool IsEatten = false;
		bool IsMoved = false;
		for (int ddir = 0; ddir < 4; ddir++) {
			int nd = shark[idx].table[shark[idx].dir][ddir]; 
			int nx = shark[idx].x + dx[nd]; 
			int ny = shark[idx].y + dy[nd];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (smell[nx][ny].first == 0) {
				if (board[nx][ny] >= 1 && board[nx][ny] < idx) {
					IsEatten = true;
					shark[idx].isLived = false;
					board[shark[idx].x][shark[idx].y] = 0;
					break;
				}
				board[shark[idx].x][shark[idx].y] = 0;
				board[nx][ny] = idx;
				shark[idx].x = nx;
				shark[idx].y = ny;
				shark[idx].dir = nd;
				IsMoved = true;
				break;
			}
		}

		if (IsEatten || IsMoved) continue;

		for (int ddir = 0; ddir < 4; ddir++) {
			int nd = shark[idx].table[shark[idx].dir][ddir];
			int nx = shark[idx].x + dx[nd];
			int ny = shark[idx].y + dy[nd];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (smell[nx][ny].first == idx) {
				board[shark[idx].x][shark[idx].y] = 0;
				board[nx][ny] = idx;
				shark[idx].x = nx;
				shark[idx].y = ny;
				shark[idx].dir = nd;
				break;
			}
		}
	}
}

void UpdateSmell() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (smell[i][j].first) smell[i][j].second--;
			if (smell[i][j].second == 0) smell[i][j].first = 0;
		}
	}
}

void MakeSmell() {
	for (int idx = 1; idx <= m; idx++) {
		if (shark[idx].isLived == false) continue; 
		smell[shark[idx].x][shark[idx].y] = { idx, k };
	}
}

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] >= 1 && board[i][j] <= m) {
				shark[board[i][j]].x = i;
				shark[board[i][j]].y = j;
				shark[board[i][j]].isLived = true;
			}
		}
	}

	for (int idx = 1; idx <= m; idx++) {
		cin >> shark[idx].dir;
		shark[idx].dir--;
	}

	for (int idx = 1; idx <= m; idx++) {
		for (int dir = 0; dir < 4; dir++) {
			for (int ddir = 0; ddir < 4; ddir++) {
				cin >> shark[idx].table[dir][ddir]; 
				shark[idx].table[dir][ddir]--;
			}
		}
	}

	int t = 0;
	MakeSmell();
	for (t = 0; t <= 1000; t++) {
		if (IsOnlyOneShark())
			break;
		MoveShark();
		UpdateSmell();
		MakeSmell();
	}

	cout << (t <= 1000 ? t : -1);
	
}