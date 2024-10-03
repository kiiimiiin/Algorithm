#include <bits/stdc++.h> 
using namespace std;

int getVal(vector<int>& array, int st, int end, int idx){
    vector<int> nArr;
    for(int i = st ; i <= end ; i++)
        nArr.push_back(array[i]);
    sort(nArr.begin(), nArr.end());
    
    return nArr[idx];
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(auto c : commands){
        int val = getVal(array, c[0]-1, c[1]-1, c[2] - 1);
        answer.push_back(val);
    }
    return answer;
}