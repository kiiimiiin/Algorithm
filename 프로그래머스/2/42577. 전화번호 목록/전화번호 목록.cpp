#include <string>
#include <unordered_set>
#include <algorithm>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_set<string> set(phone_book.begin(), phone_book.end());
    
    sort(phone_book.begin(), phone_book.end(), greater<string>());
    
    for(auto s : phone_book){
        for(int i = 1; i <= s.length() - 1; i++){
            if(set.find(s.substr(0, i )) != set.end())
                return false;
        }
    }
    
    return true;
}

/*
    글자수가 긴 순서대로, substr이 셋에 존재하는 지 확인 
    O(1000000 * 20); 
*/