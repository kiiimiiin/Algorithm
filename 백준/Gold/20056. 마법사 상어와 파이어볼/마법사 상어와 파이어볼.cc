#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

struct Fireball {
	int x, y, m, s, d;
};

vector<int> board[52][52];
vector<Fireball> fire; 
const int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int n, m, k;

pair<int, int> ProcessOOB(int x, int y) {
	if (x < 0) x = n + x;
	else if (x >= n) x = x - n;

	if (y < 0) y = n + y;
	else if (y >= n) y = y - n;

	return { x, y };
}

void Move() {
	for (int i = 0; i < fire.size(); i++) {
		if (fire[i].m <= 0) continue;
		int nx = fire[i].x + ( fire[i].s % n ) * dx[fire[i].d];
		int ny = fire[i].y + ( fire[i].s % n ) * dy[fire[i].d];
		tie(nx, ny) = ProcessOOB(nx, ny);
		board[nx][ny].push_back(i);
	}
}

void Merge() {
	vector<Fireball> temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j].empty()) continue;

			if (board[i][j].size() == 1) {
				int idx = board[i][j].front();
				temp.push_back({ i , j, fire[idx].m, fire[idx].s, fire[idx].d });
			}
			else if (board[i][j].size() >= 2) {
				int mm = 0;
				int ms = 0;
				int flag = 0;

				vector<int> dir;
				for (auto idx : board[i][j]) {
					mm += fire[idx].m;
					ms += fire[idx].s;
					flag += fire[idx].d % 2;
				}
				mm /= 5;
				ms /= board[i][j].size();
				 
				if (flag == board[i][j].size() || flag == 0)
					dir = { 0,2,4,6 };
				else
					dir = { 1,3, 5,7 };
				
				for (int d : dir) {
					if (mm <= 0) break;
					temp.push_back({ i, j, mm, ms, d });
				}		
			}
			board[i][j].clear();
		}
	}
	fire = temp;
}

int getAns() {
	int ret = 0;
	for (auto f : fire) {
		if (f.m <= 0) continue;
		ret += f.m;
	}
	return ret;
}

int main(void) {

	cin >> n >> m >> k;

	while (m--) {
		int x, y, m, s, d;
		cin >> x >> y >> m >> s >> d;
		x--; y--;
		fire.push_back({ x, y, m, s, d });
	}

	while (k--) {
		Move();
		Merge();
	}

	int ans = getAns();
	cout << ans;
}


/*

	파이어볼 구조체 배열과
	인덱스 보드
*/