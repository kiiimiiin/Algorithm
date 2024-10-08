#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int cnt, top;
    
    for(int i = 0 ; i < progresses.size(); i++){
        int date = (100 - progresses[i]) / speeds[i] + ( (100 - progresses[i]) % speeds[i] != 0);
        
        if(i == 0){
            top = date;
            cnt = 1;
            continue;
        }
        
        if(date > top){
            answer.push_back(cnt);
            cnt = 1;
            top = date;
        }
        else
           cnt++;
    }
    
    answer.push_back(cnt);
    
    return answer;
}

/*
    각 작업일자를 구함 : ( 100 - pr / sp ) + ( 100 - pr % sp )
    
    7 3 9
    앞보다 작거나 같으면 cnt를 계속 셈, 
    앞에 일자보다 커지는 순간 cnt 다시 셈, cnt push
*/