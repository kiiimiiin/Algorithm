#include <iostream>
using namespace std;
int n, m;
int d[100002]; 

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        d[i] = d[i-1] + x; 
    }
    
    while(m--){
        int i, j;
        cin >> i >> j; 
        cout << d[j] - d[i-1] << '\n';
    }
}

/*
   sum을 처음부터 구해서 구간합을 구함
   그냥 완탐으로 합구하면 시간초과
    d[i] : i까지의 수열 합
    d[i] = d[i-1] + a[i];
*/