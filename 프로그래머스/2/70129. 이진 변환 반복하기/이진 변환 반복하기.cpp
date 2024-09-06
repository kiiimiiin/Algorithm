#include <bits/stdc++.h>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    int zero = 0;
    int t=0;
    while(s != to_string(1)){
        t++;
        
        int cnt = 0;
        for(int i = 0 ; i < s.length(); i++){
            if(s[i] == '1') cnt++;
            else zero++;
        }
    
        s = "";
        while(cnt){
            char c = (cnt % 2) + '0';
            s  = c + s;
            cnt /= 2;
        }
    }
    
    answer.push_back(t);
    answer.push_back(zero);
    
    return answer;
}

/*
    0111010 에서 1의 개수 4
    4를 이진으로 변환
    100
    
    어떻게?
    2 | 4 ... 0
      | 2 ... 0
        1
        
    4 % 2 

*/