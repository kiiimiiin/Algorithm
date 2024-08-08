#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long long x = num; 
    
    while(x != 1 && answer <= 500){
        x = (x % 2 == 0 ? x / 2 : 3*x + 1);
        answer++;
    }
    
    
    
    return answer <= 500 ? answer : -1;
}