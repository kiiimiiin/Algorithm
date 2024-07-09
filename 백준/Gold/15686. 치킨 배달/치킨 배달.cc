#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second 
int n, m;
int board[52][52];
vector<pair<int,int>> house, chicken;

int main(void){
    ios::sync_with_stdio(0), cin.tie(0);
    
    
    cin >> n >> m;
    
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
            if(board[i][j] == 1)  house.push_back({i,j});
            else if(board[i][j] == 2) chicken.push_back({i,j});
        }
    }
    
    vector<int> brute(chicken.size(), 1); 
    fill(brute.begin(), brute.begin() + m , 0); 
    
    int ans = 0x7f7f7f7f; 
    do{
        
        int sum = 0; 
        for(auto h : house){
            int mn = 0x7f7f7f7f;
            for(int i = 0; i < chicken.size(); i++){
                if(brute[i] == 0){
                    int dist = abs(chicken[i].X - h.X) + abs(chicken[i].Y - h.Y);
                    mn = min(dist, mn); 
                }// 택한 치킨집
            }
            sum += mn;
        }
        ans = min(ans, sum); 
    }while(next_permutation(brute.begin(), brute.end()));

    cout << ans; 
}