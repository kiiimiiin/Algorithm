// 1. 구름 생성, 이동 , 사라짐
#include <iostream>
#include <vector>
#define X first
#define Y second
using namespace std;
int dx[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int board[52][52];
int vis[52][52];
int n, m;
vector<pair<int, int>> clouds;

pair<int, int> ProcessOOB(int x, int y) {
	int nx, ny;
	if (x < 0) nx = n + x;
	else if (x >= n) nx = x - n; // x == n -> nx == 1
	else nx = x;

	if (y < 0) ny = n + y;
	else if (y >= n) ny = y - n;
	else ny = y;

	return { nx, ny };
}

void CopyWater(vector<pair<int, int>> water) {

	for (auto pos : water) {
		int cnt = 0; // 대각선 방향 물 바구니 수
		for (int dir = 1; dir < 8; dir += 2) {
			int nx = pos.X + dx[dir];
			int ny = pos.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (board[nx][ny]) cnt++;
		}
		board[pos.X][pos.Y] += cnt;
	}
}


void Command(int d, int s) {
	// 1. 모든구름 d방향 s칸이동 , 비내리기, 물 양 증가
	vector<pair<int, int>> v;
	int removed[52][52] = {};  // 구름이 삭제된 칸

	for (auto c : clouds) {
		int nx = c.X + (s % n) * dx[d];
		int ny = c.Y + (s % n) * dy[d];
		auto ret = ProcessOOB(nx, ny);
		board[ret.X][ret.Y]++;
		removed[ret.X][ret.Y] = 1;
		v.push_back({ ret.X, ret.Y }); // 물이 증가한 칸 저장
	}

	clouds.clear();

	// 2. 물복사
	CopyWater(v);

	// 3. 바구니 칸에서 구름 생성
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] >= 2 && !removed[i][j]) {
				clouds.push_back({ i,j });
				board[i][j] -= 2;
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0), cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			board[i][j] = x; // 물양
		}
	}

	clouds.push_back({ n - 1,0 }); clouds.push_back({ n - 1,1 });
	clouds.push_back({ n - 2,0 }); clouds.push_back({ n - 2,1 });

	while (m--) {
		int d, s;
		cin >> d >> s;
		Command(d - 1, s);
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			ans += board[i][j];
	cout << ans;
}