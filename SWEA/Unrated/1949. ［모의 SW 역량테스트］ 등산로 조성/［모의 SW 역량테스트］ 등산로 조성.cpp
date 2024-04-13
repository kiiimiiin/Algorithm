#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
#include <stdio.h>
#define X first
#define Y second
using namespace std;

int n, k;
int board[10][10];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int mxh;
int mxl;
vector<pair<int, int>> mxhPos; // 높은 봉우리 위치

// 음수 일 때 고려

void FindHigh(vector<pair<int, int>>& hPoses) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			
		}
	}
}

bool OOB(int nx, int ny) {
	return (nx < 0 || nx >= n || ny < 0 || ny >= n);
}


void dfs(int x, int y, int preH, int len) { // 현재 좌표, 이전높이, 지금까지의 길이 
	
	if (OOB(x, y) || board[x][y] >= preH ) {
		mxl = max(mxl, len);
		return;
	}

	for (int dir = 0; dir < 4; dir++) { // 각 방향별 등산로 확인
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		dfs(nx, ny, board[x][y], len + 1);
	}
}
void Solve(int test_case) {
	mxhPos.clear();
	mxl = -0x7f7f7f7f; 
	mxh = -0x7f7f7f7f;


	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			
			if (board[i][j] > mxh) 
				mxh = board[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == mxh) {
				mxhPos.push_back({ i,j });
			}
		}
	}

	for (auto pos : mxhPos) { // 아무좌표또 깎지 않음
		// 가장 높은 곳에서의 등산로 길이 탐색
		dfs(pos.X, pos.Y, 0x7f7f7f7f, 0);
	}

	for (int dep = 1; dep <= k; dep++) { 
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				board[i][j] -= dep;
				// 해당 좌표에 dep이 수정된 cse에서
				
				// 등산로 설치
				
				for (auto pos : mxhPos) {
					if (pos.X == i && pos.Y == j) // dep이 수정되는 부분이 mxPos면
						continue; 
					
					// 가장 높은 곳에서의 등산로 길이 탐색
					dfs(pos.X, pos.Y, 0x7f7f7f7f, 0);
				}

				board[i][j] += dep;
				
			}
		}
	}

	cout << "#" << test_case << " " << mxl << "\n";
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	/*
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	//freopen("sample_input.txt", "r", stdin);
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{

		Solve(test_case);

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}