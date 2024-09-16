#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int n = brown + yellow;
    
    for(int r = 1; r <= n / 2; r++){
        if(n % r) continue;
        int c = n / r;
        if(yellow == (r - 2) * (c - 2)){
            answer.push_back(c);
            answer.push_back(r);
            break;
        }
    }
    return answer;
}

/*
    brown + yellow = 전체 격자 개수 n 
    
    높이 r 1부터 n / 2 까지 순회하며 그에 맞는 가로 c 찾음
    가로사이즈에 대해서 yellow = ( height - 2 ) * (c - 2)가 성립을하면 그 때 r, c return
    
*/