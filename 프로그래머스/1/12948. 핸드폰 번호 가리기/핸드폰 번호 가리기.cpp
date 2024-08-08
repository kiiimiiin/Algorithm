#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    int len = phone_number.length(); 
    int starCnt = len - 4; 
    
    for(int i = 0 ; i < starCnt ; i++){
        answer += '*';
    }
    
    for(int i = len - 4 ; i < len ; i++){
        answer += phone_number[i];
    }
    
    return answer;
}