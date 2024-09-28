#include <bits/stdc++.h>
int d[502][502];
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int n = triangle.size();
    int m = triangle[n-1].size();
    d[0][0] = triangle[0][0];
    
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= i; j++){
            d[i][j] = triangle[i][j];
            if(j == 0) d[i][j] += d[i-1][j];
            else if(j == i) d[i][j] += d[i-1][j - 1];
            else d[i][j] += max(d[i-1][j-1], d[i-1][j]);
        }
    }
    
    answer = *max_element(d[n-1], d[n-1] + m);
    return answer;
}

/*
    d[i][j] i행 j열 값이 합 최대
    
    d[0][0] = triangle[0][0];
    d[i][j] = max(d[i-1][j-1], d[i-1][j]) + triangle[i][j];
    d[i][0] = d[i-1][0] +triangle[i][j];
    d[i][j 끝] = d[i-1][j끝 -1 ] + triangle[i][j];
*/