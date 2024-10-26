#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> m;
    for(auto s : completion)
        m[s]++;
    
    for(auto s : participant){
        if(m.find(s) == m.end()){
            answer = s;
            break;
        }
        m[s]--;
        if(m[s] == 0)
            m.erase(s);
    }
    return answer;
}

/* 
    completion map만들어서
    participant 순회하며 없는 이름 찾음
*/