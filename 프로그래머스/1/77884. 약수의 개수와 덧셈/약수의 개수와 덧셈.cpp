#include <string>
#include <vector>

using namespace std;

int getCnt(int x){
    int cnt = 1;
    for(int i =1; i <= x/2 ; i++){
        if ( x % i == 0 ) cnt++;   
    }
    return cnt;
}

int solution(int left, int right) {
    int answer = 0;
    
    for(int i = left; i <= right ; i++){
        int cnt = getCnt(i);
        if(cnt % 2 == 0) answer += i;
        else answer -= i;
    }
    return answer;
}