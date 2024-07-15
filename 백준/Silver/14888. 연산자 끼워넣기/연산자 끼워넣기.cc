#include <bits/stdc++.h>
using namespace std; 
int n,x;
int num[12];
int ops[12]; 
int mx= -0x7f7f7f7f, mn = 0x7f7f7f7f; 

int main(void){
    
    ios::sync_with_stdio(0), cin.tie(0); 
    cin >> n;
    for(int i = 0 ; i < n; i++) cin >> num[i];
    
    for(int i = 0, idx = 0; i < 4; i++){
        cin >> x; 
        while(x--) ops[idx++] = i; 
    } // ops : 0 0 1 1 1 2 2 (n - 1 개)
    
    do{
        int ans = num[0];
        for(int i = 0; i < n - 1; i++){
            switch(ops[i]){
                case 0: {ans += num[i+1]; break;}
                case 1: {ans -= num[i+1]; break;}
                case 2: {ans *= num[i+1]; break;}
                case 3: {ans /= num[i+1]; break;}
            }
        }
        mx = max(mx, ans);
        mn = min(mn, ans);
        
    }while(next_permutation(ops, ops + n - 1));
    
    cout << mx << '\n' << mn;
    
}