#include <string>
#include <vector>
using namespace std;
int clothes[32];

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    fill(clothes, clothes + 32, 1);
    
    for(auto num : lost)
        clothes[num]--;
    for(auto num : reserve)
        clothes[num]++;
    
    for(int i = 1 ; i <= n; i++){
        if(clothes[i] == 2){
            if(clothes[i-1] == 0)
                clothes[i-1]++;
            else if(clothes[i+1] == 0)
                clothes[i+1]++;
            clothes[i]--;
        }
    }
    
    for(int i = 1 ; i <= n; i++)
        if(clothes[i]) answer++;
    
    return answer;
}

/*
    greedy)
    1부터 n번 학생까지 여벌이 있는 학생이면 
    앞번호가 옷이없으면 줌- 앞번호 없으면 뒷번호에게 줌
*/
