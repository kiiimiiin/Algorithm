#include <string>
#include <vector>

using namespace std;

int getOneCnt(int num){
    int ret = 0;
    while(num){
        if(num % 2)
            ret++;
        num /= 2;
    }
    return ret;
}

int solution(int n) {
    int answer = 0;
    int one_cnt = getOneCnt(n);
    int nxt = n + 1;
    while(one_cnt != getOneCnt(nxt)) 
        nxt++;
    
    answer = nxt;
    
    return answer;
}

/*
    2진변환
    
    2 | 78 .. 0
        39 .. 1
        19 .. 1
        9  .. 1
        4  .. 0
        2  .. 0
        1  

*/