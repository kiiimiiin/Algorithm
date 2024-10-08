#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int mxr, mxc;
    mxr = mxc = -0x7f7f7f7f; 
    
    for(auto v : sizes){
        mxr = max(mxr, max(v[0], v[1])); // 큰 가로중 가장 큰
        mxc = max(mxc, min(v[0], v[1])); // 작은 세로중 가장 큰 
    }

    answer = mxr * mxc;
    return answer;
}

/*

    모든 명함들을 가로가 길게, 세로를 짧게 만든다.
    
    이러한 가로중 가장 큰, 세로 중 가장 큰 것을 택

*/