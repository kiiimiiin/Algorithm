#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    vector<int> dates;
    for(int i = 0 ; i < speeds.size(); i++){
        int date = (100 - progresses[i]) / speeds[i];
        date += (100 - progresses[i]) % speeds[i] ? 1 : 0; 
        dates.push_back(date);
    }
    
    for(int i = 0 ; i < dates.size(); i++)
        cout << dates[i] << ' ';
    
    int num = dates[0];
    int cnt = 1;
    
    for(int i = 1 ; i < dates.size(); i++){
        if(num < dates[i]){
            answer.push_back(cnt);
            cnt = 1;
            num = dates[i];
        }else{
            cnt++;
        }
    }
    answer.push_back(cnt);

    return answer;
}

/*
    각 일자를 계산 
    
    ex) 7 3 9 
    
    5 10 1 1 20 1
    
    -> 1 3 2 
    
    순회하며 현재값 보다 큰 수가 나타날 때 까지 cnt
    -> 나타나면 cnt push 
    
*/