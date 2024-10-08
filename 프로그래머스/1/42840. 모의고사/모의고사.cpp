#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int pattern1[5] = {1,2,3,4,5};
    int pattern2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int pattern3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int idx1, idx2, idx3, score1, score2, score3;
    idx1 = idx2 = idx3 = score1 = score2 = score3 = 0;
    for(auto x : answers){
        if(pattern1[idx1] == x) score1++;
        if(pattern2[idx2] == x) score2++;
        if(pattern3[idx3] == x) score3++;
        idx1 = ( idx1 + 1 ) % 5;
        idx2 = ( idx2 + 1 ) % 8;
        idx3 = ( idx3 + 1 ) % 10;
    }
    
    int mx = max({score1, score2, score3});
    if(mx == score1) answer.push_back(1);
    if(mx == score2) answer.push_back(2);
    if(mx == score3) answer.push_back(3);
    return answer;
}