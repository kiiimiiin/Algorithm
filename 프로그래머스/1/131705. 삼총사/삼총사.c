#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
bool vis[14];
int idx_cse[4];
int n, answer;

void dfs(int k, int number[]){
    if( k == 3){
        int sum = 0;
        for(int i = 0 ; i < 3; i++){
            //printf("%d ", idx_cse[i]);
            sum += number[idx_cse[i]];
        }
        //printf("\n");
    
        if(sum == 0) answer++;
        return ;
    }
    
    for(int i = 0; i < n; i++){
        if(vis[i] || ( k > 0 && i <= idx_cse[k-1] )) continue;
        vis[i] = true;
        idx_cse[k] = i;
        dfs(k + 1, number);
        vis[i] = false;
    }
}
// number_len은 배열 number의 길이입니다.
int solution(int number[], size_t number_len) {
    n = number_len; 
    dfs(0,number);
    return answer;
}