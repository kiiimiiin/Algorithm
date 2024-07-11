#include <iostream>
#include <vector>
#include <algorithm>
#define X first
#define Y second
using namespace std;
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, -1, -1, -1, 0, 1, 1, 1 }; 
int mx = -0x7f7f7f7f;

struct Fish {
	int num, dir;
	bool isLive = true;
};

struct Shark {
	int x, y, dir;
};

vector<pair<int,int>> fishPos(18); // 번호에 대한 위치
Fish fish[6][6]; // 물고기 번호, 방향, 생사여부


bool OOB(int x, int y) {
	return (x < 0 || x >= 4 || y < 0 || y >= 4);
}
void MoveFish(Shark s) {
	for (int i = 1; i <= 16; i++) {
		if (!fish[fishPos[i].X][fishPos[i].Y].isLive) 
			continue; // 죽은 물고기

		auto cur = fishPos[i];
		Fish f = fish[cur.X][cur.Y];


		for (int dd = 0; dd < 8; dd++) {
			int nd = (f.dir + dd) % 8; 
			int nx = cur.X + dx[nd];
			int ny = cur.Y + dy[nd];
			if (OOB(nx, ny) || nx == s.x && ny == s.y)
				continue; 

			fishPos[i] = { nx, ny };
			fishPos[fish[nx][ny].num] = { cur.X, cur.Y };

			Fish tmp = fish[nx][ny];
			fish[nx][ny] = { i, nd };
			fish[cur.X][cur.Y] = tmp;
			break;
		}
	}
}

void Copy(Fish desc[6][6], Fish src[6][6], 
	vector<pair<int,int>>& desc2, vector<pair<int, int>>& src2) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			desc[i][j] = src[i][j];
		}
	}

	for (int i = 1; i <= 16; i++)
		desc2[i] = src2[i];
}

void dfs(Shark s, int sum) {
	
	// 0. eat
	if (fish[s.x][s.y].isLive) {
		fish[s.x][s.y].isLive = false;
		s.dir = fish[s.x][s.y].dir; 
		sum += fish[s.x][s.y].num;
		mx = max(mx, sum);
	}

	// 1. 물고기이동
	MoveFish(s);
	Fish tmp1[6][6];
	vector<pair<int, int>> tmp2(18);
	Copy(tmp1, fish, tmp2, fishPos);

	// 2. 상어이동
	for (int k = 1; k <= 3; k++) {
		int nx = s.x + k * dx[s.dir];
		int ny = s.y + k * dy[s.dir];
		if (OOB(nx, ny)) break;
		if (!fish[nx][ny].isLive) continue;
		
		// 물고기 존재
		dfs({ nx,ny,s.dir }, sum);

		Copy(fish, tmp1,fishPos, tmp2); // 원복 
	}
}


int main(void) {
	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> fish[i][j].num >> fish[i][j].dir; 
			fish[i][j].dir--;
			fishPos[fish[i][j].num] = { i,j };
		}
	}
	
	Shark s;


	s = { 0, 0, -1 }; 

	dfs(s, 0);

	cout << mx; 
	
}

/*
	1. 물고기의 이동
	2. 상어의 이동 dfs
*/