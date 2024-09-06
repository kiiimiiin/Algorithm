#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    long long answer = 0;
    long long tmp = 0;
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<int>()); 
    for(int i = 0 ; i < A.size(); i++){
        answer += A[i] * B[i];
    }
    /*
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end()); 
    
    for(int i = 0 ; i < A.size(); i++){
        tmp += A[i] * B[i];
    }
    
    answer = min(answer, tmp);
    */
    return answer;
}

/*
    배열 원소 곱의 최소를 만들려면?
    큰 원소와 작은원소의 곱이 최소라 가정 (greedy)

*/