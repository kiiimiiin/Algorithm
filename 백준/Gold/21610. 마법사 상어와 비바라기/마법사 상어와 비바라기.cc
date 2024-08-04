#include <iostream>
#include <queue>
#include <utility>
#include <tuple>
#define X first
#define Y second
const int dx[8] = { 0,-1,-1,-1,0,1,1,1 };
const int dy[8] = { -1,-1,0,1,1,1,0,-1 };
using namespace std;

int board[52][52];
int cloud[52][52];
int n, m, d, s;

pair<int, int> ProcessOOB(int x, int y) {
	if (x < 0) x = n + x;
	else if (x >= n) x = x - n;

	if (y < 0) y = n + y;
	else if (y >= n) y = y - n;
	
	return { x, y };
}

void doMagic(int d, int s) {
	int temp[52][52] = {};

	// 1. 구름 이동, 비내리기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (cloud[i][j]) {
				int nx = i + ( s * dx[d] ) % n;
				int ny = j + ( s * dy[d] ) % n;
				tie(nx, ny) = ProcessOOB(nx, ny);
				temp[nx][ny]++;
				board[nx][ny]++;
				cloud[i][j] = 0;
			}
		}
	}

	// 2. 물증가 칸 마법시전
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (temp[i][j]) {
				for (int dir : { 1, 3, 5, 7}) {
					int nx = i + dx[dir];
					int ny = j + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (board[nx][ny]) {
						board[i][j]++;
					}
				}
			}
		}
	}

	// 3. 구름 재 생성
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] >= 2 && !temp[i][j]) {
				board[i][j] -= 2;
				cloud[i][j] = 1;
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


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0); 

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	cloud[n - 1][0] = cloud[n - 1][1] = 
		cloud[n - 2][0] = cloud[n - 2][1] = 1;



	while (m--) {
		cin >> d >> s; 
		d--;
		doMagic(d, s);
	}

	int ans;
	ans = getAns();
	cout << ans;
	
}

/*
	구름 보드
*/