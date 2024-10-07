#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    
    for(auto x : arr){
        if(answer.empty() || answer.back() != x)
            answer.push_back(x);
    }
    return answer;
}

/*
    arr 순회하며 비어있거나 (첫원소), back이랑 다르면 push

*/