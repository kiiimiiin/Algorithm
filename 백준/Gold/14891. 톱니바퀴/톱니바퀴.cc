#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
char gear[4][8];
int k;

void Rotate(int n, int d) {
	int dirs[4] = {};
	dirs[n] = d;

	// 우측 회전방향 전파
	for (int i = n + 1; i < 4; i++) {
		if (gear[i - 1][2] == gear[i][6]) break;
		dirs[i] = -dirs[i - 1];
	}
	// 좌측
	for (int i = n - 1; i >= 0; i--) {
		if (gear[i + 1][6] == gear[i][2]) break;
		dirs[i] = -dirs[i + 1];
	}
	
	for (int i = 0; i < 4; i++) {
		if (dirs[i] == 1) 
			rotate(gear[i], gear[i] + 7, gear[i] + 8);
		else if (dirs[i] == -1) 
			rotate(gear[i], gear[i] + 1, gear[i] + 8);
	}
}

int main(void) {
		
	for (int i = 0; i < 4; i++) 
		for (int j = 0; j < 8; j++)
			cin >> gear[i][j];
	
	cin >> k;

	while (k--) {
		int n, d; 
		cin >> n >> d;
		Rotate(n-1, d);
	}

	int ans = 0;
	for (int i = 0; i < 4; i++) {
		if (gear[i][0] == '1') ans += (1 << i);
	}
	cout << ans;
}


/*
	12시방향 : 01234567
	1. k번 특정 바퀴를 회전
		1.1 옆 바퀴는 맞물리는 방향이 같으면 회전을안함
		1.2 맞물리는 방향이 다르면 반대방향으로 회전
		1.3 이 회전은 옆으로 계속 전파를 한다.

	2. 각 바퀴의 0번 인덱스를 순회하여 점수구함
*/