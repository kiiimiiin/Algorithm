#include <iostream>
#include <algorithm>
using namespace std;
int d[100002];
int n, x;

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    
    cin >> n;
    
    for(int i = 1 ; i <= n; i++){
        cin >> x;
        d[i] = max(d[i-1] + x, x);
    }
    
    cout << *max_element(d + 1, d + n + 1);
    
}


/*
    d[i] : i번째 까지의 최대 연속합
    
   i번째가 연속 일 때 d[i-1] + num[i]
   i번째가 연속이 아닐 때 num[i]
     
*/