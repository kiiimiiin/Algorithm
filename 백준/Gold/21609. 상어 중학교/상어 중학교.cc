#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#define X first
#define Y second
using namespace std;
int dx[4] = { 1,0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int board[22][22];
int vis[22][22];
int n, m; 
struct Block {
	int x, y;
	int num;
	int rainbow_num;
	int area;
};

vector<Block> blocks;
vector<pair<int,int>> block_positions[22][22];

void TestBlock() {
	cout << "TestBlock:\n";
	for (auto block : blocks) {
		cout << "Block info(x,y,rainbow,area):" << block.x << ','
			<< block.y << ',' << block.rainbow_num << ',' << block.area
			<< '\n';
		for (auto pos : block_positions[block.x][block.y]) {
			cout << "(" << pos.X << "," << pos.Y << ") ";
		}
		cout << "\n\n";
	}
}

void TestBoard() {
	cout << "TestBoard:\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
}

void BfsForGrouping(int x, int y) {
	vector<pair<int, int>> v;
	queue<pair<int, int>> q;
	int area = 0;
	int rainbow_num = 0;
	int color = board[x][y];
	
	q.push({ x,y });
	vis[x][y] = 1;

	while (!q.empty()) {
		auto cur = q.front(); q.pop(); area++;
		if (board[cur.X][cur.Y] == 0) rainbow_num++;
		v.push_back({ cur.X, cur.Y });

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (board[nx][ny] < 0 || vis[nx][ny]) continue;
			if (board[nx][ny] > 0 && color != board[nx][ny])
				continue;
			q.push({ nx,ny });
			vis[nx][ny] = 1;
		}
	}
	if (area < 2 ) { // 블록이 1개
		vis[x][y] = 0;
		return;
	}
	Block block;
	block.x = x; block.y = y; 
	block.rainbow_num = rainbow_num;  block.area = area;
	blocks.push_back(block);
	block_positions[block.x][block.y] = v;
	for (auto pos : block_positions[block.x][block.y]) 
		if (board[pos.X][pos.Y] == 0) vis[pos.X][pos.Y] = 0;
	// ** 무지개 다리에 대한 방문기록 초기화
	return;
}

void Grouping(){
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] > 0 && !vis[i][j]) { //BFS ( 일반블록 1개이상 )
				BfsForGrouping(i,j);
			}
		}
	}
}

void Rotate() {
	int c_board[22][22] = {};
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++)
			c_board[n-1-j][i] = board[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			board[i][j] = c_board[i][j];
}
void DoGravity() {
	
	for (int j = 0; j < n; j++) {
		for (int i = n - 2; i >= 0; i--) {
			if (board[i][j] == -1) continue;
			if (board[i][j] == -2) continue;
			int color = board[i][j];
			int nx = i + 1;
			while (1) {
				if (board[nx][j] == -2) {
					nx++;
					continue;
				}
				else if (board[nx][j] >= -1 || nx >= n) {
					nx--;
					break;
				}
			}
			board[i][j] = -2;
			board[nx][j] = color;
		}
	}
}
int AutoPlay() {
	int score = 0;

	// 1. 블락그룹 선택
	int point = -1;
	int choosed_idx = -1;
	for (int i = blocks.size()-1; i >= 0; i--) {
		int cur_point = 0;
		cur_point += 10 * blocks[i].area;
		cur_point += 1 * blocks[i].rainbow_num;
		if (cur_point > point) {
			choosed_idx = i;
			point = cur_point;
		}
			
	}

	if (choosed_idx == -1) return 0;
	// 2. 블락그룹 제거
	Block choosed_block = blocks[choosed_idx];
	score += choosed_block.area * choosed_block.area; 
	for (auto pos : block_positions[choosed_block.x][choosed_block.y]) {
		board[pos.X][pos.Y] = -2; // 비어있는 칸
	}
	
	// 3. 중력, 회전 , 중력

	DoGravity();
	Rotate();
	DoGravity();

	return score;
	
}

void Clear() {
	// 기존 정보들 클리어
	for (int i = 0; i < n; i++) fill(vis[i], vis[i] + n, 0);
	blocks.clear();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			block_positions[i][j].clear();
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++)
			cin >> board[i][j];

	int ans = 0;
	while (1) {
		Clear();
		Grouping();
		int score = AutoPlay();
		if (score == 0) break;
		ans += score;
	}
	
	cout << ans;
}