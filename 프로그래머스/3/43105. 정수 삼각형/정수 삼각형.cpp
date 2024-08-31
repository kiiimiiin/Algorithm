#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;

    vector<vector<int>> d(triangle.size());
    for(int i = 0 ; i < triangle.size(); i++){
        d[i].resize(triangle[i].size());
    }
    
    d[0][0] = triangle[0][0];
    for(int i = 1 ; i < triangle.size(); i++){
        for(int j = 0 ; j < triangle[i].size(); j++){
            if (j == 0)
                d[i][j] = d[i-1][j] + triangle[i][j];
            else if ( j == i)
                d[i][j] = d[i-1][j-1] + triangle[i][j];
            else
                d[i][j] = max(d[i-1][j-1], d[i-1][j]) + triangle[i][j];
        }
    }
    

    int n = triangle.size();
    answer = *max_element(d[n - 1].begin(),  d[n - 1].begin() + n); 
    return answer;
}