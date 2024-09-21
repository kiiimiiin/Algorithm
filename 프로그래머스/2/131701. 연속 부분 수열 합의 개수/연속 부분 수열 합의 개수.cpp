#include <bits/stdc++.h>
using namespace std;
int sum[2004];

int solution(vector<int> elements) {
    int answer = 0;
    int len = elements.size();
    unordered_set<int> s;
    
    for(int i = 0 ; i < len - 1; i++){
        elements.push_back(elements[i]);
    }
    
    sum[0] = elements[0];
    for(int i = 1; i < elements.size(); i++){
        sum[i] = sum[i - 1] + elements[i];
        cout << sum[i] << ' ';
    }
    
    for(int l = 0; l < len; l++){
        s.insert(sum[l]);
        for(int i = 1; i < len; i++)
            s.insert(sum[i + l] - sum[i - 1]);
    }
    
    answer = s.size();

    return answer;
}

/*
    앞과 끝을 이어붙인다
    7 9 1 1 4 7 9 1 1 4
    길이별로 배열순회
    O(n^2)
*/