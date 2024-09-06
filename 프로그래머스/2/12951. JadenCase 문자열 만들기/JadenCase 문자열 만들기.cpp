#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";

    bool isFirst = true; 
    
    for(int i = 0; i < s.length(); i++){
        if(s[i] == ' '){
            isFirst = true;
            continue; 
        }
             
        if(isFirst){
            if(islower(s[i])) s[i] = toupper(s[i]);
            isFirst = false;
        } else {
            if(isupper(s[i])) s[i] = tolower(s[i]);
        }
        
        
    }
    
    return s;
}

