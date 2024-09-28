#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    answer.push_back(arr[0]);
    
    for(int i = 1; i < arr.size(); i++){
        if(answer.back() != arr[i])
            answer.push_back(arr[i]);
    }
    
    return answer;
}

/*
    스택의 top과 다를 때마다 arr값을 push
*/