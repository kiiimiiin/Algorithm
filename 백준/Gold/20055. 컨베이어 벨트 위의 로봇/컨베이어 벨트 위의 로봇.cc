#include <iostream>
#include <algorithm> 
#include <deque>
#include <vector>
using namespace std;

vector<int> belt(202, 0); // 사이즈, 초기값
int robots[101];
int N,K;

void TestBelt(){
    cout << "Belt:\n";
    for(int i = 0 ; i <= N-1; i++) cout << belt[i] << ' ';
    cout << '\n';
    for(int i = 2*N-1; i >= N; i--) cout << belt[i] << ' ';
    cout << '\n';
}

void TestRobot(){
    cout << "Robot:\n";
    for(int i = 0; i <= N-1; i++) cout << robots[i] << ' '; 
    cout << '\n';
}

 
int main(void){
    ios::sync_with_stdio(0), cin.tie(0);
    
    cin >> N >> K;
    for(int i = 0; i < 2 * N; i++){
        int life;
        cin >> life; 
        belt[i] = life;
    } // belt 내구도 채움
    
    
    int ans = 0;
    while(1){
        ans++;
        // 1. 벨트 회전 ( rotate 가운데가 1번째 자리로 가야한다)
        // 및 로봇을 우측으로 이동
        rotate(belt.begin(), belt.begin() + 2*N - 1 , belt.begin() + 2*N);
        for(int i = N-2; i >= 0; i--){
            if(robots[i] == 0) continue;
            robots[i]--;
            robots[i+1]++;
            if(i==N-2) robots[i+1]--;
        }
        
        // 2. 로봇이동
        // 첫번째부터 모든 로봇에 대해서 이동을 해야함
        for(int i = N-2; i >= 0; i--){
            if(robots[i]){
                if(robots[i+1]) continue; // nx칸에 로봇이 존재
                if(belt[i+1] == 0) continue; // nx칸이 부서짐
                robots[i]--;
                robots[i+1]++;
                if(i==N-2) robots[i+1]--;
                belt[i+1]--;
            }
        }
        
        // 3. 로봇 올림
        if(belt[0]){
            robots[0]++; 
            belt[0]--;
        }
        
        // 4. 내구도 0 칸 k개이상시 종료
        int num = 0;
        for(int i = 0 ; i < 2 * N; i++){
            if(belt[i] == 0) num++;
        }
        if(num >= K) break;
    }
    cout << ans;
}
