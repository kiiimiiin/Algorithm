#include <bits/stdc++.h>
using namespace std;
char gear[4][8]; 
int k;

void rot(int idx, int dir){
    int dirs[4] = {};
    
    dirs[idx] = dir; 
    
    int i = idx; 
    while(i > 0){
        if(gear[i-1][2] == gear[i][6]) break;
        else dirs[i-1] = -dirs[i]; // 맞물린 극 다름
        i--;
    }
    
    i = idx; 
    while(i < 4){
        if(gear[i+1][6] == gear[i][2]) break;
        else dirs[i+1] = -dirs[i]; // 맞물린 극 다름
        i++;
    } // rot정보저장
    
    for(int i = 0 ; i < 4; i++){
        if(dirs[i] == 1){ // 시계
            for(int j = 7 ; j > 0 ; j--)
                swap(gear[i][j], gear[i][j-1]);    
        }
        else if(dirs[i] == -1){ // 반시계
            for(int j = 0; j < 7; j++)
                swap(gear[i][j], gear[i][j+1]);
        }
    }
    
}

int main(void){
    ios::sync_with_stdio(0), cin.tie(0);
    
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 8; j++)
            cin >> gear[i][j];
    
    cin >> k;
    while(k--){
        int n, dir;
        
        cin >> n >> dir;
        
        rot(n-1, dir);
    }
    
    int ans = 0;
    
    for(int i = 0; i < 4; i++)
        if(gear[i][0] == '1') ans += (1 << i); 

    cout << ans;
}