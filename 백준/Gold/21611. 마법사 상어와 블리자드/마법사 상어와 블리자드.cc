// 각 칸 번호를 설정, 그 칸에 해당하는 구슬값
// 만약 14번칸이 파괴되면 14번 부터 뒤에있는 구슬들은 앞으로 밀림

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define X first
#define Y second
using namespace std;
int dx[4] = { 0, 1, 0,-1 };  // 오 아래 왼 위
int dy[4] = { 1, 0, -1, 0 };
int ans[4]; 

int board[52][52]; // 보드 구슬 값
int spaceNum[52][52]; // 칸 번호 보드
int marbleCnt[2500]; // 칸 번호에 대응하는 구슬 값
int n,m ,sx, sy;

void TestMarbel() {
	cout << "TestMarbel:\n";
	for (int i = 0; i < n * n; i++) {
		cout << "(" << i << "," << marbleCnt[i] << ") ";
	}
}

void TestIdx() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << spaceNum[i][j] << ' ';
		}
		cout << '\n';
	}
}

void TestBoard() {
	cout << '\n';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
}

void MakeSetting() {
	// 공간번호 및 번호에 해당하는 구슬 갯수 초기화 
	int x, y, dir;
	x = y = dir = 0;
	int num = n * n - 1;
	for (int i = 0; i < n; i++) fill(spaceNum[i], spaceNum[i] + n, -1);

	while (num) {
		spaceNum[x][y] = num;
		marbleCnt[num] = board[x][y];
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (ny >= n || nx >= n || ny < 0 || spaceNum[nx][ny] >= 0) {
			dir = (dir + 1) % 4;
			nx = x + dx[dir];
			ny = y + dy[dir];
		}
		x = nx; y = ny;
		num--;
	}
	spaceNum[sx][sy] = 0;
	marbleCnt[0] = 0;
}

void PushMarble(int tNum) {
	// 파괴된 첫번째 칸에서부터 끝칸까지 앞으로 밀어넣음
	queue<int> q;
	for (int num = tNum; num <= spaceNum[0][0]; num++) {
		if (marbleCnt[num] > 0) q.push(marbleCnt[num]);
	}

	for (int num = tNum; num <= spaceNum[0][0]; num++) {
		if (!q.empty()) {
			marbleCnt[num] = q.front();
			q.pop();
		}
		else
			marbleCnt[num] = 0;
	}
}

int BoomMarble() {
	bool isFirstFinded = 1;
	int firstNumber = -1;
	int sameCnt = 0;
	for (int num = 1; num <= spaceNum[0][0]; num = num + sameCnt) {
		if (marbleCnt[num] == 0) break;
		sameCnt = 0;
		while ((num + sameCnt) <= spaceNum[0][0] &&
			marbleCnt[num] == marbleCnt[num + sameCnt]) {
			sameCnt++;
		}
		if (sameCnt < 4) {
			continue;
		}
		else { // 4칸 이상인 경우 Check
			if (isFirstFinded) {
				firstNumber = num;
				isFirstFinded = 0;
			}
			for (int i = 0; i < sameCnt; i++) {
				ans[marbleCnt[num + i]]++;
				marbleCnt[num + i] = 0;
			}
		}
	}

	
	return firstNumber;
}

void CopyMarbleToBoard() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			board[i][j] = marbleCnt[spaceNum[i][j]];
}
void DoBlizard(int d, int s) {
	int bdx[4] = { -1, 1, 0, 0 };
	int bdy[4] = { 0, 0 , -1, 1 };
	
	// 1. 구슬 파괴

	int fx, fy;
	for (int ts = s; ts > 0; ts--) {
		int tx = sx + ts * bdx[d];
		int ty = sy + ts * bdy[d];
		marbleCnt[spaceNum[tx][ty]] = 0;
		fx = tx;
		fy = ty;
	}
	
	PushMarble(spaceNum[fx][fy]);
	//CopyMarbleToBoard();
	

	//TestBoard

	// 2. 구슬 폭발

	
	int fn;
	while (1) {
		fn = BoomMarble();
		if (fn < 0) break;
		else PushMarble(fn);
	}

	//CopyMarbleToBoard();

	//TestBoard();

	queue<int> q;
	// 3. 그룹별 구슬 변환
	int sameCnt;
	for (int num = 1; num <= spaceNum[0][0];  num = num + sameCnt) {
		if (marbleCnt[num] == 0) break;
		sameCnt = 0;
		while ((num + sameCnt) <= spaceNum[0][0] &&
			marbleCnt[num] == marbleCnt[num + sameCnt]) {
			sameCnt++;
		}
		q.push(sameCnt);
		q.push(marbleCnt[num]);
	}

	for (int num = 1; num <= spaceNum[0][0]; num++) {
		if (!q.empty()) {
			marbleCnt[num] = q.front();
			q.pop();
		}
		else
			marbleCnt[num] = 0;
	}

	//CopyMarbleToBoard();
	//TestBoard();
}


int GetAns() {
	int ret = 0;
	for (int i = 1; i <= 3; i++) {
		ret += i * ans[i];
	}
	return ret;
}

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	sx = sy = (n - 1) / 2;

	fill(marbleCnt, marbleCnt + n * n, -1);
	MakeSetting();
	// 각 칸 번호 설정
	while (m--) {
		int d, s;
		cin >> d >> s;
		DoBlizard(d-1, s);
	}

	//TestBoard();
	cout << GetAns();
	
}