#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> dates;
    
    for(int i = 0 ; i < progresses.size(); i++){
        int date = ( 100 - progresses[i] ) / speeds[i] + 
            ( ( 100 - progresses[i] ) % speeds[i] ? 1 : 0 ) ;    
        dates.push_back(date);
    }
    
    int cnt = 0;
    int lastDate = 0;
    for(int i = 0 ; i < dates.size(); i++){
        if(i == 0){
            lastDate = dates[i];
            cnt++;
        }
        else if(dates[i] <= lastDate){
            cnt++;
        }
        else{
            answer.push_back(cnt);
            lastDate = dates[i];
            cnt = 1;
        }
    }
            
    answer.push_back(cnt);
    
    return answer;
}