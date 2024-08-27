#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer(1, 1);
    int idx = 0; 
    int mxDate = ( 100 - progresses[0] ) / speeds[0];
    if((100 - progresses[0]) % speeds[0]) mxDate++;
    
    for(int i = 1; i < progresses.size(); i++){
        int date = ( 100 - progresses[i] ) / speeds[i]; 
        if((100 - progresses[i]) % speeds[i]) date++;
        if(date <= mxDate) answer[idx]++;
        else{
            mxDate = date;
            answer.push_back(1);
            idx++;
        }
        
    }
    return answer;
}

/*
    7일 3일 9일
    앞에서부터 걸리는 일자수 계산해나감
    뒤에 나타나는게 걸리는 일자수보다 작거나 같을때 + 1, 클때 새로운 원소

*/