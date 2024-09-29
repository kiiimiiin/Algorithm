#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    for(long long i = left; i <= right; i++){
        int r = i / n;
        int c = i % n;
        answer.push_back(max(r, c) + 1);
    }
    return answer;
}

/*
    
    0 1 2 1 2 3
    3 4 5 2 2 3
    6 7 8 3 3 3
    
        열 0 1 2 (나머지)
   (몫)
    행 0 : 1 2 3     0 1 2 
    행 1 : 2 2 3     3 4 5 
    행 2 : 3 3 3     6 7 8
    
    행이 0이다 -> 열 1부터 +1
    행이 1이다 -> 열 2부터 +1 그전 열은 행 + 1
    행이 2이다 -> 열 3부터 +1 그전 열은 행 + 1
*/