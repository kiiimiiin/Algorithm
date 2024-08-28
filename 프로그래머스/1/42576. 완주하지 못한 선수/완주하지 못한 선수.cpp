#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_multiset<string> ms(completion.begin(), completion.end());
    for(auto s : participant){
        
        if(ms.find(s) != ms.end()) 
            ms.erase(ms.find(s));
        else {
            answer = s;
            break;
        }
    }
    
    return answer;
}