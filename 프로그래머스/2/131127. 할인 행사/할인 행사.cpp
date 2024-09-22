#include <bits/stdc++.h>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    int len = discount.size() - 10;
    unordered_map<string, int> m, tmp;
    
    for(int i = 0 ; i < want.size(); i++)
        m[want[i]] = number[i];
    
    for(int i = 0 ; i < 10; i++)
        tmp[discount[i]]++;
    if(tmp == m) answer++;
    
    for(int i = 1 ; i <= len; i++){ 
        tmp[discount[i-1]]--;
        tmp[discount[i+9]]++;
        
        if(tmp[discount[i-1]] == 0) tmp.erase(discount[i-1]);
        if(tmp == m) answer++;
    }
    
    return answer;
}

/*
    idx : dicountLen - numberLen 까지
    
    14 - 10 : 4 
    0 ~ 4까지
    돌아가며 10길이만큼 해시맵 비교
*/