#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
#include <queue>
#define X first
#define Y second
using namespace std;
int dx[8] = { 0,-1,-1,-1,0,1,1,1 };
int dy[8] = { -1,-1,0,1,1,1,0,-1 };
int n, m;
int board[52][52];
int cloud[52][52];

void ProcessOOB(int& nx, int& ny) {
	if (nx >= n) nx = nx - n;
	else if (nx < 0) nx = n + nx; 

	if (ny >= n) ny = ny - n;
	else if (ny < 0) ny = n + ny;
}

void Magic(int dir, int s) {
	// move cloud

	int tmp[52][52] = {};

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (cloud[i][j] == 0) continue;
			int nx = i + (s % n) * dx[dir];
			int ny = j + (s % n) * dy[dir];
			ProcessOOB(nx, ny);
			tmp[nx][ny] = 1;
			cloud[i][j] = 0;
		}
	}

	//rain
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (tmp[i][j])
				board[i][j]++;
	
	// copy
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (tmp[i][j]) {
				int cnt = 0;
				for (auto d : { 1, 3, 5, 7 }) {
					int nx = i + dx[d];
					int ny = j + dy[d];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (board[nx][ny] == 0) continue;
					cnt++;
				}
				board[i][j] += cnt;
			}
		}
	}

	// make cloud
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (tmp[i][j]) continue;
			if (board[i][j] >= 2) {
				cloud[i][j] = 1;
				board[i][j] -= 2;
			}
		}
	}
}

int getAns() {
	int ret = 0; 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ret += board[i][j];
		}
	}
	return ret;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	cloud[n - 1][0] = cloud[n - 1][1]
		= cloud[n - 2][0] = cloud[n - 2][1] = 1;

	while (m--) {
		int d, s;
		cin >> d >> s;
		Magic(d - 1, s);
	}

	int ans = getAns();
	cout << ans;
}