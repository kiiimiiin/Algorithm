#include <unordered_set>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_multiset<string> ms(completion.begin(), completion.end());
    for(auto x : participant){
        auto it = ms.find(x); 
        if(it == ms.end()){
            answer = x;
            break;
        } else{
            ms.erase(it);
        }
    }
    
    return answer;
}

/*
    '동명이인 존재 가능'
    완주자들을 해시셋으로 만든다.
    참가자들을 순회하며 완주자에 없다면 완주 x 선수
    
*/