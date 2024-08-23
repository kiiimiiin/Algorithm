#include <iostream>
using namespace std;
long long d[102], n, t;

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> t;
    
    d[1] = d[2] = d[3] = 1;
    d[4] = d[5] = 2;
    
    for(int i = 6; i <= 100; i++){
        d[i] = d[i-1] + d[i-5];
    }
    
    while(t--){
        cin >> n;
        cout << d[n] << '\n';
    }
    
}

/*
    d[i] : i번째 정삼각형 변의 길이
    
    d[1] = d[2] = d[3] = 1; 
    d[4] = d[5] = 2;
    
    d[i] = d[i-1] + d[i-5];

*/