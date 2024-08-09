#include <iostream>
#include <tuple>
#include <queue>
#define X first
#define Y second
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
using namespace std;

struct Info {
	int near[4]; // 하, 우, 상, 좌 에 대한 정보
	int stuNum = 0; // 학생정보
};

struct Student {
	int num;
	int friendNum[4]; 
	int x = -1, y = -1;
};

vector<Student> student;
int board[402][402];
int n;

bool OOB(int x, int y) {
	return (x < 0 || x >= n || y < 0 || y >= n);
}

pair<int,int> Set(int num, int friendNum[4]) {

	pair<int, int> pos;
	pair<int, int> mx = { -0x7f7f7f7f, -0x7f7f7f7f };

	for (int i = n - 1; i >= 0; i--) {
		for (int j = n - 1; j >= 0; j--) {
			if (board[i][j]) continue; 
			int nearEmpty = 0;
			int nearFriend = 0;
			for (int dir = 0; dir < 4; dir++) {
				int nx = i + dx[dir];
				int ny = j + dy[dir];
				if (OOB(nx, ny)) continue;
				if (board[nx][ny] == 0) {
					nearEmpty++;
				}
				else {
					for (int i = 0; i < 4; i++) {
						if (friendNum[i] == board[nx][ny]) {
							nearFriend++;
							break;
						}
					}
				}
			}

			if (make_pair(nearFriend, nearEmpty) >= mx) {
				mx = make_pair(nearFriend, nearEmpty);
				pos = make_pair(i, j);
			}
		}
	}


	board[pos.X][pos.Y] = num;
	return pos;

}
int Solve() {

	// 학생 배치 
	for (int i = 0; i < student.size(); i++) {
		int x, y;
		tie(x, y) = Set(student[i].num, student[i].friendNum);
		student[i].x = x;
		student[i].y = y;
	}

	// 만족도 구하기 
	int ret = 0;
	for (int i = 0; i < student.size(); i++) {
		int nearFriend = 0;
		for (int dir = 0; dir < 4; dir++) {
			int nx = student[i].x + dx[dir];
			int ny = student[i].y + dy[dir];
			if (OOB(nx, ny)) continue;
			for (int j = 0; j < 4; j++) {
				if (student[i].friendNum[j] == board[nx][ny]) {
					nearFriend++;
					break;
				}
			}
		}
		if (nearFriend == 0) ret += 0;
		else if (nearFriend == 1) ret += 1;
		else if (nearFriend == 2) ret += 10;
		else if (nearFriend == 3) ret += 100;
		else ret += 1000;
	}

	return ret;

}
int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	cin >> n; 
	
	for (int i = 0; i < (n * n); i++) {
		Student stu;
		cin >> stu.num;
		for (int i = 0; i < 4; i++)
			cin >> stu.friendNum[i];
		student.push_back(stu); 
	}


	int ans = Solve();
	cout << ans;
}




/*
	학생 배열 테이블
*/