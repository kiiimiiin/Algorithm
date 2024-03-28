#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Fish {
	int x, y;
	int dir;
	bool isLive;
};
int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0, -1, -1,-1,0,1,1,1 };
int mx = -0x7f7f7f7f;
Fish fishes[17]; // 번호에 해당하는 물고기정보, 0은 dummy
int board[5][5]; // 물고기 번호 보드


bool OOB(int x, int y) {
	return (x < 0 || x >= 4 || y < 0 || y >= 4);
}

void MoveFish() {

	for (int num = 1; num <= 16; num++) {
		if (!fishes[num].isLive) continue;

		int nx, ny; // 이동할 수 있는 칸 찾음.
		int cnt = 8;
		while (cnt--) {
			nx = fishes[num].x + dx[fishes[num].dir];
			ny = fishes[num].y + dy[fishes[num].dir];
			if (OOB(nx, ny) || board[nx][ny] == -2) {
				fishes[num].dir = (fishes[num].dir + 1) % 8;
				continue;
			}
			else
				break; 
		} // 타겟 위치 방향 설정

		if (cnt >= 0) {// 물고기 존재 : 위치변환
			int targetNum = board[nx][ny];

			board[nx][ny] = num;
			board[fishes[num].x][fishes[num].y] = targetNum; // 보드 정보 수정

			fishes[targetNum].x = fishes[num].x;
			fishes[targetNum].y = fishes[num].y;

			fishes[num].x = nx;
			fishes[num].y = ny; // 번호별 물고기 정보 수정
			
		}
	}
}

void Copy(int desc[5][5], int src[5][5], Fish desc2[17], Fish src2[17]) {
	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 4; y++) {
			desc[x][y] = src[x][y]; 
		}
	}

	for (int num = 1; num <= 16; num++) 
		desc2[num] = src2[num];
}

void dfs(int sum, int sx, int sy, int sd) {
	mx = max(mx, sum);

	int cBoard[5][5]; Fish cFishes[17]; 
	Copy(cBoard, board, cFishes, fishes);
	MoveFish();
	

	for (int s = 1; s <= 3; s++) {
		int snx = sx + s * dx[sd];
		int sny = sy + s * dy[sd];
		if (OOB(snx, sny)) break;
		if (board[snx][sny] == 0) continue;
		
		
		int targetNumber = board[snx][sny];
		int snd = fishes[targetNumber].dir;
		fishes[targetNumber].isLive = false;
		board[sx][sy] = 0;
		board[snx][sny] = -2;
		dfs(sum + targetNumber, snx, sny, snd);

		
		fishes[targetNumber].isLive = true;
		board[sx][sy] = -2;
		board[snx][sny] = targetNumber;
	}

	Copy(board, cBoard, fishes, cFishes);
}


int main(void) {

	for (int x = 0; x < 4 ; x++) {
		for (int y = 0; y < 4; y++) {
			int num, dir; 
			cin >> num >> dir;
			fishes[num] = { x, y, dir-1, true };
			board[x][y] = num;
		}
	}

	// (0,0) 먹기
	int sx, sy, sd, sum;
	sx = 0; sy = 0; sum = board[0][0];
	sd = fishes[board[0][0]].dir; 
	fishes[board[0][0]].isLive = false;
	board[0][0] = -2;
	
	dfs(sum, sx, sy, sd);
	
	cout << mx;

}