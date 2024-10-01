#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> m;
    for(auto v : clothes)
        m[v[1]]++;
    
    
    for(auto e : m)
        answer *= e.second + 1; 
    
    answer--;
    
    return answer;
}

/*
 
    
    x 모자1 모자2
    x 선글라스1
    
    3 * 2 - 1 (아예 옷을 안 입는경우)
    
*/