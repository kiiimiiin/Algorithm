#include <iostream>
#define MODULER 1000000000
using namespace std;
int n;
long long d[102][10];
int main(){
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> n;
    
    for(int i = 1; i <= 9; i++) d[1][i] = 1;
    
    d[1][0] = 0;
    
    for(int i = 2; i <= n; i++){
        for(int j = 0 ; j <= 9; j++){
            if(j == 0) d[i][j] = d[i-1][j+1] % MODULER;
            else if(j == 9) d[i][j] = d[i-1][j-1] % MODULER;
            else d[i][j] = d[i-1][j+1] + d[i-1][j-1] % MODULER;
        }
    }
    
    long long ans = 0;
    for(int i = 0; i <= 9; i++) ans += d[n][i];
    cout << ans % MODULER;
}


/*
    d[i][j] : i번째 길이의 끝자리수가 j일때 계단수
    
    1 : 1 2 3 4 5 6 7 8 9
    
    2 : 10 11 21 12 32 43 23 54 34 65 45 76 56 87 67 98 78 89

    3 : 110 210 121 321 101
    
    4 : 1010 1012 ... 


*/