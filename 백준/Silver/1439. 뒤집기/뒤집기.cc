#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
int vis0[1000002]; 
int vis1[1000002];
string s; 
queue<int> q0;
queue<int> q1;
int zeroCnt, oneCnt; 

int main()
{
    cin >> s;
    int len = s.length(); 
    
    for(int i = 0 ; i < len; i++){
        if(s[i] == '0' && !vis0[i]){
            zeroCnt++;            
            q0.push(i);
            vis0[i] = 1;
            while(!q0.empty()){
                int cur = q0.front(); q0.pop();
                for(int dx : { -1 ,1 }){
                    int nx = cur + dx;
                    if(nx < 0 || nx >= len || vis0[nx] || s[nx] == '1') 
                        continue;
                    vis0[nx] = 1;
                    q0.push(nx);
                }    
            }
        }
        else if(s[i] == '1' && !vis1[i]){
            oneCnt++;            
            q1.push(i);
            vis1[i] = 1;
            while(!q1.empty()){
                int cur = q1.front(); q1.pop();
                for(int dx : { -1 ,1 }){
                    int nx = cur + dx;
                    if(nx < 0 || nx >= len || vis1[nx] || s[nx] == '0') 
                        continue;
                    vis1[nx] = 1;
                    q1.push(nx);
                }    
            }
        }
    }
    cout << ( zeroCnt == 0 || oneCnt == 0 ? 0 : min(zeroCnt, oneCnt) );
}



/*
    greedy
    1의 영역 개수
    0의 영역 개수 중 최소

*/