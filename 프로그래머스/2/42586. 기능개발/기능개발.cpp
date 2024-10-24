#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int cnt = 0;
    int top = -0x7f7f7f7f;
    
    for(int i = 0; i < progresses.size(); i++){
        int val = ( 100 - progresses[i] ) / speeds[i];
        val += (100 - progresses[i]) % speeds[i] > 0;
        if(i == 0){
            top = val;
            cnt++;
            continue;
        }
        
        if(top < val){
            top = val;
            answer.push_back(cnt);
            cnt = 1;
            continue;
        }
        
        cnt++;
    }
    
    answer.push_back(cnt);
    return answer;
}

/*
    마지막 몇개 세고있는지는 종료전에 반영한다.
*/