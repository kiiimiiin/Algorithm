#include <iostream>
#include <utility>
#include <vector>
#include <unordered_set>
#define X first
#define Y second
using namespace std;
int n, m;
int board[51][51];
int dy[8] = { -1,-1,0,1,1,1,0,-1 };
int dx[8] = { 0,-1,-1,-1,0,1,1,1 };
vector<pair<int, int>> clouds;

void Magic(int d, int s) {
	bool isMagiced[51][51] = {};
	for (auto& c : clouds) {
		int nx = ( c.X + (s % n ) * dx[d] + n ) % n;
		int ny = ( c.Y + (s % n ) * dy[d] + n ) % n;
		board[nx][ny]++;
		isMagiced[nx][ny] = true;
		c = { nx, ny };
	}

	for (auto& c : clouds) {
		for (int dir = 1; dir < 8; dir += 2) {
			int nx = c.X + dx[dir];
			int ny = c.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (board[nx][ny]) {
				board[c.X][c.Y]++;
			}
		}
	}

	clouds.clear();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] >= 2 && !isMagiced[i][j]) {
				board[i][j] -= 2;
				clouds.push_back({ i,j });
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

	clouds.push_back({ n - 1,0 });
	clouds.push_back({ n - 1,1 });
	clouds.push_back({ n - 2,0 });
	clouds.push_back({ n - 2,1 });

	while (m--) {
		int d, s;
		cin >> d >> s;
		Magic(d-1, s);
	}
	cout << getAns();
}