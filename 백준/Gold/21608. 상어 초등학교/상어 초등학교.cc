#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#define X first
#define Y second
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
using namespace std;
int board[22][22];
int is_impossible[4002];
int N, ans;
vector<vector<int>> students;


void TestBoard() {
	cout << "TestBoard\n:";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
}
bool OOB(int nx, int ny) {
	return (nx < 0 || nx >= N || ny < 0 || ny >= N);
}

pair<int,int> FindEmpty(vector<pair<int, int>> candi) {
	// 2. 빈칸 인접칸 많은 자리 반환
	vector<pair<int,int>> empty_candi[5];
	for (auto pos : candi) {
		int near_empty_num = 0;
		for (int dir = 0; dir < 4; dir++) {
			int nx = pos.X + dx[dir];
			int ny = pos.Y + dy[dir];
			if (OOB(nx, ny)) continue;
			if (board[nx][ny] == 0) near_empty_num++;
		}
		empty_candi[near_empty_num].push_back({ pos.X, pos.Y });
	}

	pair<int, int> ret;
	for (int i = 4; i >= 0; i--) {
		if (empty_candi[i].empty()) continue;
		// 2.1 빈칸 많은 칸 발견
		
		// 유일할 때 OR 유일하지 않을 때 -> 행,열 조건에 맞는 칸 탐색
		// 예외 : 빈칸이 없는 경우도 3번조건에 맞춰서 가능. 
		if(empty_candi[i].size() >= 2)
			sort(empty_candi[i].begin(), empty_candi[i].end()); // 오름차순
		ret = empty_candi[i].front(); break;
	}
	return ret;
}



tuple<int,int,int> ChooseSpace(vector<int> student) {
	// 조건에 맞는 자리택하는 함수 
	int num = student.front();

	// 1. 좋아하는 학생 많은 칸 탐색
	vector<pair<int, int>> candi[5]; // near_num에 대한 candi
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (is_impossible[board[i][j]]) continue; // 이미 택한경우 스킵
			int near_num = 0;
			for (int dir = 0; dir < 4; dir++) {
				int nx = i + dx[dir];
				int ny = j + dy[dir];
				if (OOB(nx, ny)) continue;
				
				for (int k = 1; k < student.size(); k++)
					if (board[nx][ny] == student[k]) near_num++; // 인접 좋아하는 학생수
			}

			candi[near_num].push_back({ i,j }); 
		}
	}

	pair<int, int> pos;

	for (int i = 4; i >= 0; i--) {
		if (candi[i].empty()) continue; 
		// 1.1 주변 좋아하는 학생 많은 칸 발견
		// 1.1.1 유일한 칸 발견
		// 예외 i == 0 -> 좋아하는 학생 있는 칸 없음
		if (candi[i].size() == 1) { 
			pos = candi[i].front();
		}
		// 1.1.2 유일하지 않은 경우 -> 빈칸 많은 칸 탐색
		else {
			pos = FindEmpty(candi[i]);
		}
		break;
	}
	/* 
	// 1.2 주변 좋아하는 학생 없는경우 -> 빈칸 많은 칸 탐색
	vector<pair<int, int>> all_poses; 
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			all_poses.push_back({ i,j });
	pos = FindEmpty(all_poses);
	return { num, pos.X, pos.Y };
	*/
	return { num, pos.X, pos.Y };

}


int main(void) {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;

	for (int i = 0; i < N * N; i++) {
		int num, preferred_num;
		vector<int> student;
		cin >> num;
		student.push_back(num);
		for (int j = 0; j < 4; j++) {
			cin >> preferred_num;
			student.push_back(preferred_num);
		}
		students.push_back(student);
	} // front : num, 이후 : preferred_num

	// 가장 먼저 들어온 학생먼저 
	// 1. 좋아하는 학생 인접칸 많은 자리 (아예 없다면 2번넘어감)
	// 2. 인접한 칸 중에 비어 있는 칸 많은 자리
	// 3. 행 번호 작은자리, 같으면 열번호 작은자리

	for (int i = 0; i < students.size(); i++){
		vector<int> student = students[i];
		auto pos = ChooseSpace(student);
		board[get<1>(pos)][get<2>(pos)] = get<0>(pos);
		is_impossible[get<0>(pos)] = 1;
	}

	for (int l = 0; l < students.size(); l++) {
		auto student = students[l];
		int num = students[l].front();
		bool is_finded = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (board[i][j] != num) continue;
				int near_num = 0;
				for (int dir = 0; dir < 4; dir++) {
					int nx = i + dx[dir];
					int ny = j + dy[dir];
					if (OOB(nx, ny)) continue;
					for (int k = 1; k < student.size(); k++)
						if (board[nx][ny] == student[k]) near_num++;	
				}
				if (near_num == 1) ans += 1;
				else if (near_num == 2) ans += 10;
				else if (near_num == 3) ans += 100;
				else if (near_num == 4) ans += 1000;
				is_finded = 1; break;
			}
			if (is_finded) break;
		}
	}
	cout << ans;
}