#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

bool solution(vector<string> phone_book) {
    bool flag[22] = {};
    unordered_set<string> s;
    
    for(auto e : phone_book){
        s.insert(e);
        flag[e.size()] = true;
    }
    
    for(auto e : s){
        for(int i = 1 ; i <= 20; i++){
            if(flag[i] && i < e.size()){
                if(s.find(e.substr(0, i)) == s.end()) continue;
                return false;
            }
        }
    }
    
    return true;
}


/*
    글자수들을 기록해서 자기글자보다 작은 글자들에 대해 find 
    -> 같으면 접두어가 아님! 자기자신을 찾음
    O(20 * N)
*/