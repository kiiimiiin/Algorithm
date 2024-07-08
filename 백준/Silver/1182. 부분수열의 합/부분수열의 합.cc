#include <iostream>
#include <algorithm>
using namespace std;
int n, s, ans;
int arr[22];

void dfs(int k, int sum){
    
    if(k == n){
        if(sum == s) ans++;
        return ;
    }
    
    
    dfs(k + 1, sum + arr[k]);
    dfs(k + 1, sum);
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> s;
    for(int i = 0 ;  i < n; i++) cin >> arr[i];
    dfs(0, 0);
    cout << (s == 0 ? ans -1 : ans);
}