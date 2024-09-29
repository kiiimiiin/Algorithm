#include <string>
#include <vector>

using namespace std;

int getNum(int i, int j,vector<vector<int>>& arr1,vector<vector<int>>& arr2){
    int num = 0;
    for(int k = 0; k < arr1[0].size(); k++){
        num += arr1[i][k] * arr2[k][j];
    }
    return num;
}

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int r = arr1.size();
    int c = arr2[0].size();
    vector<vector<int>> answer(r,vector<int>(c,0));
    
    for(int i = 0 ; i < r; i++)
        for(int j = 0 ; j < c; j++)
            answer[i][j] = getNum(i, j, arr1, arr2);
    
    return answer;
}

/*
    
    0, 0은 1번째 행렬의 0행, 2번째 행렬의 0열 곱합
    1, 0은 1번째 행렬의 1행, 2번째 행렬의 0열
    
    1 4        3 3 
    3 2        3 3
    4 1
    
    3 x 2    2 x 2
    
    -> 3 x 2 행렬
    
    3 + 12 3 + 12
    
    9 + 6 ...
    ... ... 
    
        0 1
    0   
    1
    2
    
*/