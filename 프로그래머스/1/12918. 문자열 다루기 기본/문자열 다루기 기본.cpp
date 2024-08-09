#include <string>
#include <vector>
#include <cctype>

using namespace std;


bool solution(string s) {
    bool answer = true;
    int len = s.length();
    
    if(!(len == 4 || len == 6)) return false;
        
    for(int i = 0; i < len; i++){
        if(isalpha(s[i])) return false;
    }
    
    
    return true;
}