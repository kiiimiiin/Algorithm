#include <bits/stdc++.h>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = false;
    unordered_set<string> set(phone_book.begin(), phone_book.end());
    sort(phone_book.begin(), phone_book.end());
    
    for(auto s : phone_book){
        string tmp = "";
        for(int i = 0; i < s.length() - 1; i++){
            tmp.push_back(s[i]);
            if( set.find(tmp) != set.end())
                return answer;
        }
    }
    
    answer = true;
    return answer;
}

/*
    전화번호 오름차순 sort : 길이가 짧은 것부터 접두어 탐색하기 위해, 
    
    1235면 1, 12, 123 탐색 (자기자신 제외)
    
    O(2600만)
*/