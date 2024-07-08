#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int marr[10];
int narr[10];
bool isused[10];

void dfs(int k){
    if(k == m){
        for(int i = 0 ; i < m; i++){
            cout << marr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    
    for(int i = 0; i < n; i++){
        if(marr[k-1] > narr[i] && k > 0) continue;
        if(!isused[i]){
            marr[k] = narr[i];
            isused[i] = true;
            dfs(k + 1);
            isused[i] = false;
        }
    }
}


int main(void){
    ios::sync_with_stdio(0), cin.tie(0);
    
    cin >> n >> m;
    
    for(int i = 0 ; i < n; i++) cin >> narr[i];
    sort(narr, narr+n);
    
    dfs(0);
    
}