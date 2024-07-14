#include <iostream>
#define X first; 
#define Y second;
using namespace std;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 }; 
int board[52][52]; 
int r, c, t, head, tail; 

bool OOB(int x, int y) {
	return (x < 0 || x >= r || y < 0 || y >= c);
}
void spread() {
	int cBoard[52][52] = {} ;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (board[i][j] > 0) {
				for (int dir = 0; dir < 4; dir++) {
					int nx = i + dx[dir];
					int ny = j + dy[dir];
					if (OOB(nx, ny) || board[nx][ny] == -1) continue;
					cBoard[nx][ny] += board[i][j] / 5;
					cBoard[i][j] -= board[i][j] / 5; 
				}
			}
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			board[i][j] += cBoard[i][j];
		}
	}
}

void clean() {
	
	// x : head - 1을 시작으로 수를 head쪽으로 밀자
	int x, y, nx, ny, dir; 
	int hdx[4] = { -1, 0, 1, 0 };
	int hdy[4] = { 0, 1, 0, -1 };
	x = head - 1; 
	y = 0; 
	dir = 0;
	nx = ny = 0; 

	while (1) {
		nx = x + hdx[dir];
		ny = y + hdy[dir];
		if (nx == head && ny == 0) break;
		if (nx < 0 || ny >= c || nx > head) {
			dir = (dir + 1) % 4; 
			continue; 
		}
		board[x][y] = board[nx][ny]; 
		x = nx; y = ny; 
	}
	board[x][y] = 0; 

	int tdx[4] = { 1, 0, -1, 0 };
	int tdy[4] = { 0, 1, 0, -1 };
	x = tail + 1;
	y = 0;
	dir = 0;
	nx = ny = 0;

	while (1) {
		nx = x + tdx[dir];
		ny = y + tdy[dir];
		if (nx == tail && ny == 0) break;
		if (nx >= r || ny >= c || nx < tail) {
			dir = (dir + 1) % 4;
			continue;
		}
		board[x][y] = board[nx][ny];
		x = nx; y = ny;
	}
	board[x][y] = 0;
}

int getAns() {
	int ret = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (board[i][j] == -1) continue;
			ret += board[i][j]; 
		}
	}
	return ret; 
}

int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> r >> c >> t; 

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			int n;
			cin >> n;
			board[i][j] = n;
			if (n == -1) {
				tail = i; 
			}
		}
	}

	head = tail - 1;

	while (t--) {
		spread();
		clean(); 
	}

	int ans = getAns(); 
	cout << ans;
}