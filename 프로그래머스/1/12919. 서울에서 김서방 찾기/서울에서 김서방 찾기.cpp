#include <string>
#include <vector>
#include <string>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    int idx = 0;
    answer += "김서방은 ";
    
    for(int i = 0 ; i < seoul.size(); i++){
        if(seoul[i] == "Kim") idx = i;
    }
    
    answer += to_string(idx) + "에 있다";
    return answer;
}