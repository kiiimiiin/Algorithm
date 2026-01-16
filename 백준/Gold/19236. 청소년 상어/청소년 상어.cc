#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,-1,-1,-1,0,1,1,1 };
int board[4][4];

struct Fish {
	int x, y, dir;
	bool isLived = false;
};

Fish fishes[17];

void MoveFish(int sx, int sy) {
	for (int idx = 1; idx <= 16; idx++) {
		if (fishes[idx].isLived == false) continue;
		
		for(int dd = 0 ; dd < 8; dd++){
			int nd = (fishes[idx].dir + dd) % 8; 
			int nx = fishes[idx].x + dx[nd];
			int ny = fishes[idx].y + dy[nd];			
			if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
			if (nx == sx && ny == sy) continue;
			// temp or fish
			int cx = fishes[idx].x;
			int cy = fishes[idx].y;

			fishes[idx].x = nx;
			fishes[idx].y = ny;
			fishes[idx].dir = nd;
			fishes[board[nx][ny]].x = cx;
			fishes[board[nx][ny]].y = cy;
			swap(board[nx][ny], board[cx][cy]);
			break;
		}
	}

	return; 
}

void Copy(int desc[4][4], int src[4][4], Fish fdes[17], Fish fsrc[17]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			desc[i][j] = src[i][j];
		}
	}

	for (int i = 0; i < 17; i++) {
		fdes[i] = fsrc[i];
	}

	return;
}
void dfs(int sx, int sy, int sum, int& ans) {

	int sd = fishes[board[sx][sy]].dir;
	fishes[board[sx][sy]].isLived = false;
	sum += board[sx][sy]; ans = max(ans, sum);
	board[sx][sy] = 0;

	MoveFish(sx, sy);
	
	int temp[4][4] = {};
	Fish ftemp[17] = {};
	
	Copy(temp, board, ftemp, fishes);

	for (int p = 1; p <= 3; p++) {
		int nx = sx + p * dx[sd];
		int ny = sy + p * dy[sd];
		if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue; 
		if (board[nx][ny] == 0) continue; 
		dfs(nx, ny, sum, ans);
		Copy(board, temp, fishes, ftemp);
	}
}

int main()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int idx, dir;
			cin >> idx >> dir;
			board[i][j] = idx;
			fishes[idx] = { i, j, dir - 1, true};
		}
	}
	int ans = -0x7f7f7f7f;
	dfs(0, 0, 0, ans);
	std::cout << ans;
}