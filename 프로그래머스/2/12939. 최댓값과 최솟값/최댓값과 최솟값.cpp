#include <bits/stdc++.h>
using namespace std;

string solution(string s) {
    string answer = "";
    int mx = -0x7f7f7f7f;
    int mn = 0x7f7f7f7f;
    
    string tmp = "";
    for(int i = 0; i <= s.length(); i++){
        if(isdigit(s[i]) || s[i] == '-'){
            tmp += s[i];
        }
        if(s[i] == ' ' || s[i] == '\0'){
            int num = stoi(tmp);
            mx = max(mx, num);
            mn = min(mn, num);
            tmp = "";
        }
    }
    
    answer = to_string(mn) + " " + to_string(mx);
    return answer;
}