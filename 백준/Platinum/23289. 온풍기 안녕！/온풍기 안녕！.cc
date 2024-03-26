#include <iostream>
#include <vector>
#include <tuple>
#include <utility>
#include <queue>
#define X first
#define Y second
using namespace std;

int temp[22][22]; // 온도
int board[22][22]; 
bool wall[22][22][4] = { false, };
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0 , 0 }; // 오 왼 위 아래
int r, c, k, w; // k : 조사하는 칸 온도 k이상이면 중단 | w : 벽의 개수
vector<tuple<int,int, int>> machines; // (방향,{좌표})
vector<pair<int, int>> targets; // 조사하는 칸 좌표

bool OOB(int x, int y) {
	return (x < 1 || x > r || y < 1 || y > c);
}

void Wind(int wdir, int x, int y) {
	if (wall[x][y][wdir]) return;

	queue<pair<int, int>> q;
	int addedBoard[22][22] = {};
	int wx, wy; // 기준이되는 바람 좌표
	wx = x + dx[wdir];
	wy = y + dy[wdir];
	if (OOB(wx, wy)) return;
	
	q.push({ wx,wy });
	addedBoard[wx][wy] = 5;

	if (wdir == 0) {// 오
		int wdx[3] = { 1, 0, -1 };
		int wdy[3] = { 1, 1, 1 };

		while (!q.empty()) {
			auto cur = q.front(); q.pop();
			if (addedBoard[cur.X][cur.Y] == 1) break;
			for (int dir = 0; dir < 3; dir++) {
				int nx = cur.X + wdx[dir];
				int ny = cur.Y + wdy[dir];
				if (OOB(nx, ny)) continue;
				if (addedBoard[nx][ny]) continue;
				if (dir == 0 &&(wall[cur.X + 1][cur.Y][2] || wall[cur.X + 1][cur.Y][0]))
						continue;
				else if (dir == 1 && wall[cur.X][cur.Y][0])
						continue;
				else if (dir == 2 && (wall[cur.X-1][cur.Y][3] || wall[cur.X - 1][cur.Y][0]))
						continue;

				addedBoard[nx][ny] = addedBoard[cur.X][cur.Y]-1;
				q.push({ nx,ny });
			}
		}
	}
	else if (wdir == 1) {// 왼
		int wdx[3] = { 1, 0, -1 };
		int wdy[3] = { -1, -1, -1 };

		while (!q.empty()) {
			auto cur = q.front(); q.pop();
			if (addedBoard[cur.X][cur.Y] == 1) break;
			for (int dir = 0; dir < 3; dir++) {
				int nx = cur.X + wdx[dir];
				int ny = cur.Y + wdy[dir];
				if (OOB(nx, ny)) continue;
				if (addedBoard[nx][ny]) continue;
				if (dir == 0 && (wall[cur.X + 1][cur.Y][2] || wall[cur.X + 1][cur.Y][1]))
					continue;
				else if (dir == 1 && wall[cur.X][cur.Y][1])
					continue;
				else if (dir == 2 && (wall[cur.X - 1][cur.Y][3] || wall[cur.X - 1][cur.Y][1]))
					continue;

				addedBoard[nx][ny] = addedBoard[cur.X][cur.Y] - 1;
				q.push({ nx,ny });
			}
		}
	}
	else if (wdir == 2) {// 위
		int wdx[3] = { -1, -1, -1 };
		int wdy[3] = { 1, 0, -1 };

		while (!q.empty()) {
			auto cur = q.front(); q.pop();
			if (addedBoard[cur.X][cur.Y] == 1) break;
			for (int dir = 0; dir < 3; dir++) {
				int nx = cur.X + wdx[dir];
				int ny = cur.Y + wdy[dir];
				if (OOB(nx, ny)) continue;
				if (addedBoard[nx][ny]) continue;
				if (dir == 0 && (wall[cur.X][cur.Y+1][1] || wall[cur.X][cur.Y+1][2]))
					continue;
				else if (dir == 1 && wall[cur.X][cur.Y][2])
					continue;
				else if (dir == 2 && (wall[cur.X][cur.Y-1][0] || wall[cur.X][cur.Y-1][2]))
					continue;

				addedBoard[nx][ny] = addedBoard[cur.X][cur.Y] - 1;
				q.push({ nx,ny });
			}
		}
	}
	else if (wdir == 3) {// 아래
		int wdx[3] = { 1, 1, 1 };
		int wdy[3] = { 1, 0, -1 };

		while (!q.empty()) {
			auto cur = q.front(); q.pop();
			if (addedBoard[cur.X][cur.Y] == 1) break;
			for (int dir = 0; dir < 3; dir++) {
				int nx = cur.X + wdx[dir];
				int ny = cur.Y + wdy[dir];
				if (OOB(nx, ny)) continue;
				if (addedBoard[nx][ny]) continue;
				if (dir == 0 && (wall[cur.X][cur.Y+1][1] || wall[cur.X][cur.Y+1][3]))
					continue;
				else if (dir == 1 && wall[cur.X][cur.Y][3])
					continue;
				else if (dir == 2 && (wall[cur.X][cur.Y-1][0] || wall[cur.X][cur.Y-1][3]))
					continue;

				addedBoard[nx][ny] = addedBoard[cur.X][cur.Y] - 1;
				q.push({ nx,ny });
			}
		}
	}

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			temp[i][j] += addedBoard[i][j];
		}
	}
}



void WindByAllMachines() {
	for (auto m : machines) {
		int dir, x, y;
		tie(dir, x, y) = m;
		Wind(dir, x, y);
	}
}

void ControlTemp() {
	int diffTemp[22][22] = {};
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (temp[i][j]) {
				for (int dir = 0; dir < 4; dir++) {
					int nx = i + dx[dir];
					int ny = j + dy[dir];
					if (OOB(nx, ny)) continue;
					if (wall[i][j][dir]) continue;
					if (temp[i][j] - temp[nx][ny] > 0) {
						int diff = temp[i][j] - temp[nx][ny];
						diffTemp[i][j] -= diff / 4;
						diffTemp[nx][ny] += diff / 4;
					}
				}
			}
		}
	}
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			temp[i][j] += diffTemp[i][j];

	// 바깥쪽 칸 온도조절
	
	for (int i = 2; i <= r-1; i++) {
		if (temp[i][1]) temp[i][1]--;
		if (temp[i][c]) temp[i][c]--;
	}
	for (int j = 2; j <= c-1; j++) {
		if (temp[1][j]) temp[1][j]--;
		if (temp[r][j]) temp[r][j]--;
	}

	for (int i : {1, c}) {
		if (temp[1][i]) temp[1][i]--;
		if (temp[r][i]) temp[r][i]--;
	}

}

void TestTemp() {
	cout << "\n";
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cout << temp[i][j] << ' ';
		}
		cout << '\n';
	}
}

bool DetectTarget() {
	for (auto t : targets) {
		if (temp[t.X][t.Y] < k) return false;
	}
	return true;
}

int main(void) {
	cin >> r >> c >> k;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> board[i][j];
			if (board[i][j] >= 1 && board[i][j] <= 4)
				machines.push_back({ board[i][j] - 1, i, j });
			else if (board[i][j] == 5)
				targets.push_back({ i,j });
		}
	}


	cin >> w;
	while (w--) {
		int x, y, dir; 
		cin >> x >> y >> dir;
		if (dir == 0) {
			wall[x][y][2] = true;
			wall[x - 1][y][3] = true;
		}
		else if (dir == 1) {
			wall[x][y][0] = true;
			wall[x][y + 1][1]  = true;
		}
	}

	int ans = 0;
	while (1) {
		WindByAllMachines();
		ControlTemp();
		ans++;
		//TestTemp();
		if (DetectTarget() || ans > 100) break;
	}
	cout <<  ans;
}