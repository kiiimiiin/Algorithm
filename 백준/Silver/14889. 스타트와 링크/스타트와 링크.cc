#include <bits/stdc++.h>
using namespace std;
int n;
int board[22][22];
int t;

int main(void){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    
    for(int i = 0; i < n ; i++)
        for(int j = 0; j < n ; j++)
            cin >> board[i][j];
            
    vector<int> brute(n, 1);
    fill(brute.begin(), brute.begin() + n / 2, 0); // 0 0 0 0 .. 1 1 1 1
    
    int mn = 0x7f7f7f7f;
    do{
        vector<int> start;
        vector<int> link;
        for(int i = 0 ; i < n; i++){
            if(brute[i] == 0) start.push_back(i); // 0 1 2 3 
            else link.push_back(i);
        }

        
        int sum_s, sum_l;
        sum_s = sum_l = 0; 
        for(int i = 0 ; i < start.size(); i++)
            for(int j = i + 1; j < start.size(); j++)
                sum_s += board[start[i]][start[j]] + board[start[j]][start[i]];
        
        for(int i = 0 ; i < link.size(); i++)
            for(int j = i + 1; j < link.size(); j++)
                sum_l += board[link[i]][link[j]] + board[link[j]][link[i]];
        
        int res = abs(sum_s - sum_l);
        mn = min(mn, res);
    }while(next_permutation(brute.begin(), brute.end()));
    
    cout << mn;
}