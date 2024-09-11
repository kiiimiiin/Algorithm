#include <bits/stdc++.h>
int sum[2002];
using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    int len = elements.size();
    
    unordered_set <int> s;
    
    for(int i = 0; i < len -1 ; i++)
        elements.push_back(elements[i]);
    
    sum[0] = elements[0];
    for(int i = 1; i < elements.size(); i++)
        sum[i] = sum[i - 1] + elements[i];
        
    
    for(int l = 0; l < len; l++){
        for(int i = 0; i <= len - 1; i++){
            s.insert( i == 0 ? sum[i + l] : sum[i + l] - sum[i - 1]);
        } 
        cout << '\n';
    }
    
    answer = s.size();
    
    return answer;
}

/*
    길이 1000
    
    1000 * (1000 ) = O(N^2)

*/