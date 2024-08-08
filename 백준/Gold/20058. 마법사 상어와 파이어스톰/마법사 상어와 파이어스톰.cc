#include <iostream>
#include <tuple>
#include <queue>
#define X first
#define Y second
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
using namespace std;
int board[66][66];
int temp[66][66];
int n, q, l, N, iceSum, mxArea;

bool OOB(int x, int y) {
	return x < 0 || x >= N || y < 0 || y >= N;
}

pair<int, int> getAns() {

	queue<pair<int, int>> q;
	int vis[66][66] = {};
	int sum = 0;
	int mx = -0x7f7f7f7f;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] > 0 && !vis[i][j]) {
				int area = 0;
				q.push({ i,j });
				vis[i][j] = 1;
				while (!q.empty()) {
					auto cur = q.front(); q.pop(); area++;
					sum += board[cur.X][cur.Y];
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (OOB(nx, ny) || vis[nx][ny]) continue;
						if (board[nx][ny] > 0) {
							q.push({ nx,ny });
							vis[nx][ny] = 1;
						}
					}
				}
				mx = max(mx, area);
			}
		}
	}

	mx = (mx == -0x7f7f7f7f ? 0 : mx);

	return { sum, mx }; 
}



void subRotate(int x, int y, int L) {
	
	for (int i = x; i < x + L; i++) {
		for (int j = y; j < y +  L; j++) {
			temp[(j - y)][L - 1 - (i - x)] = board[i][j];
		}
	}

	for (int i = 0; i < L; i++) {
		for (int j = 0; j < L; j++) {
			board[i + x][j + y] = temp[i][j];
		}
	}
}


void Rotate(int L) {
	for (int i = 0; i < N; i += L) {
		for (int j = 0; j < N; j += L) {
			subRotate(i, j, L);
		}
	}
}



void Melt() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] > 0) {
				int cnt = 0;
				for (int dir = 0; dir < 4; dir++) {
					int nx = i + dx[dir];
					int ny = j + dy[dir];
					if (OOB(nx, ny)) continue;
					if (board[nx][ny] > 0)
						cnt++;
				}
				if (cnt >= 3)
					temp[i][j] = board[i][j];
				else
					temp[i][j] = board[i][j] - 1;
			}
			else
				temp[i][j] = 0;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			board[i][j] = temp[i][j];
		}
	}
}

int main(void) {
	cin >> n >> q;
	N = (1 << n); 
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j]; 
		}
	}

	while (q--) {
		cin >> l;
		if (l > 0) {
			int L = (1 << l);
			Rotate(L);
		}
		Melt();
	}


	tie(iceSum, mxArea) = getAns();
	cout << iceSum << '\n' << mxArea;
}