#include <bits/stdc++.h>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    unordered_map<string, int> m, tmp; 
    
    for(int i = 0; i < want.size(); i++)
        m[want[i]] = number[i];    
    
    
    for(int i = 0 ; i < 10; i++)
        tmp[discount[i]]++;
    
    if(m == tmp) answer++;
    
    for(int i = 1; i <= discount.size() - 10; i++){
        tmp[discount[i-1]]--;
        if(tmp[discount[i-1]] == 0) tmp.erase(discount[i-1]);
        tmp[discount[i+9]]++;
        if(m == tmp) answer++;
    }
    
    return answer;
}

 
/*
    해시맵에 기록해놓고  discount 선형순회하며 조건에 맞을때마다 count 
    복잡도 O(100000)

*/