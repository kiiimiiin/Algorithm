#include <string>
#include <vector>

using namespace std;

int getCnt(int tmp){
    int cnt = 0;
    while(tmp){
        if (tmp % 2) cnt++;
        tmp /= 2;
    }
    return cnt;
}
int solution(int n) {
    int answer = 0;
    
    int cnt = getCnt(n); 
    
    
    for(int i = n + 1; i <= 1000000 ; i++){
        if( cnt == getCnt(i)){
            answer = i;
            break;
        }
    }    
    
    return answer;
}

/*
    2 | 4 ... 0
    2 | 2 ... 0
        1 
*/