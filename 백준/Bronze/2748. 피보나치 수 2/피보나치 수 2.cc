#include <iostream>
using namespace std;
int n;
long long d[100];

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n; 
    d[0] = 0;
    d[1] = 1;
    
    for(int i = 2; i <= n; i++){
        d[i] = d[i-1] + d[i-2];
    }
    
    cout << d[n];
    
}

/*
    복잡도로 인해 재귀로 못품
    d[i] : i번째 피보나치 수
    d[i] = d[i-1] + d[i-2]
    d[0] = 0
    d[1] = 1
    
*/