#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> dates;
    for(int i = 0; i < progresses.size(); i++){
        int date = ( 100 - progresses[i] ) / speeds[i] +
            (( 100 - progresses[i] ) % speeds[i] ? 1 : 0) ;
        
        if(answer.empty() || date > dates.back()){
            answer.push_back(1);
            dates.push_back(date);
        }
        else if(date <= dates.back()){
            answer.back()++;
        }
    
        
    }
    return answer;
}