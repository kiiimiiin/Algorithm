#include <iostream>
#include <algorithm>
using namespace std;
int n;
int board[502][502];
int dirBoard[502][502];

const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { 1, 0, -1, 0 }; // 우하좌상

const int ratio[4][5][5] = {
	{
		{0,0,2,0,0},
		{0,1,7,10,0},
		{0,0,0,0,5},
		{0,1,7,10,0},
		{0,0,2,0,0},
	}
	,
	{
		{0,0,0,0,0},
		{0,1,0,1,0},
		{2,7,0,7,2},
		{0,10,0,10,0},
		{0,0,5,0,0},
	}
	,
	{
		{0,0,2,0,0},	
		{0,10,7,1,0},
		{5,0,0,0,0},
		{0,10,7,1,0},
		{0,0,2,0,0},
	}
	,
		{
		{0,0,5,0,0},
		{0,10,0,10,0},
		{2,7,0,7,2},
		{0,1,0,1,0},
		{0,0,0,0,0},
	}
};

bool OOB(int x, int y) {
	return x < 0 || x >= n || y < 0 || y >= n; 
}

void MakeSnail() {
	for (int i = 0; i < n; i++) 
		fill(dirBoard[i], dirBoard[i] + n, -1);
	
	int x = 0;
	int y = 0;
	int dir = 0; 
	dirBoard[x][y] = (dir + 2) % 4;
	
	
	while (dirBoard[n / 2][n / 2] == -1) {
		int nx = x + dx[dir];
		int ny = y + dy[dir]; 
		if (OOB(nx, ny) || dirBoard[nx][ny] != -1) {
			dir = (dir + 1) % 4;
			continue;
		}
		dirBoard[nx][ny] = (dir + 2) % 4;
		x = nx; 
		y = ny;
	}
}

int subSpread(int x, int y, int dir) {
	int cDust = board[x][y];
	int outDust = 0, sumDust = 0;
	int nx, ny, a;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			int r = ratio[dir][i][j];
			int dust = cDust * r / 100;
			nx = i + (x - 2);
			ny = j + (y - 2);
			
			if (OOB(nx, ny)) {
				outDust += dust;
			}
			else {
				board[nx][ny] += dust;
			}
			sumDust += dust;
		}
	}
	
	nx = x + dx[dir];
	ny = y + dy[dir];
	a = cDust - sumDust;
	if (OOB(nx, ny))
		outDust += a;
	else
		board[nx][ny] += a;

	return outDust; 
}

int Spread() {
	int outDust = 0;
	int x = n / 2;
	int y = n / 2; 
	while (!(x == 0 && y == 0)) {
		int dir = dirBoard[x][y];
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		outDust += subSpread(nx, ny, dir);
		x = nx;
		y = ny;
	}
	return outDust; 
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j]; 
		}
	}

	MakeSnail();
	int ans = Spread();
	cout << ans; 
}

