#include <bits/stdc++.h>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_set<string> s(phone_book.begin(), phone_book.end());
    
    sort(phone_book.begin(), phone_book.end());
    
    for(auto hp : phone_book){
        string tmp = "";
        for(int i = 0 ; i < hp.length() - 1; i++){
            tmp += hp[i];
            if(s.find(tmp) != s.end())
                return false;
        }
    }
    
    return true;
}

/*
    O(2천만)
*/