#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int wearCnt[33];

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    
    fill(wearCnt + 1, wearCnt + n + 1, 1);
    
    for(auto idx : lost)
        wearCnt[idx]--;
    
    for(auto idx : reserve)
        wearCnt[idx]++;
    
    for(int i = 1 ; i <= n; i++){
        if(wearCnt[i] == 0){
            if( i - 1 >= 1 && wearCnt[i-1] == 2 )
            {
                wearCnt[i]++;
                wearCnt[i-1]--;
            }
            else if(i + 1 <= n && wearCnt[i+1] == 2) {
                wearCnt[i]++;
                wearCnt[i+1]--;
            }
        }
    }
    
        
    for(int i = 1; i <= n; i++) 
        answer += wearCnt[i] >= 1 ? 1 : 0;       
    return answer;
}