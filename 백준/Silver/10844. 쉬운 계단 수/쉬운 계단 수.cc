#include <iostream>
using namespace std;
int n;
long long d[102][10];
int main(){
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> n;
    
    for(int i = 1; i <= 9; i++) d[1][i] = 1;
    
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= 9; j++){
            if(j == 1){
                if(i <= 2)
                    d[i][1] = (1 + d[i-1][2]) % 1000000000;
                else
                    d[i][1] = (d[i-2][1] + d[i-1][2]) % 1000000000;
            }
                 
            else if(j == 9) 
                d[i][9] = d[i-1][8] % 1000000000 ;
            else 
                d[i][j] = (d[i-1][j-1] + d[i-1][j+1]) % 1000000000;
        }
    }
    
    long long ans = 0;
    for(int i = 1; i <= 9; i++)
        ans += d[n][i] % 1000000000;
    cout << ans % 1000000000;
}


/*
    d[i][j] : i번째 길이의 첫번째 수가 j일때 계단수
    
    1 : 1 2 3 4 5 6 7 8 9
    
    2 : 10 12 21 23 32 34 43 45 54 56 65 67 76 78 87 89 98 

    3 : 101 121 123  987
    
    4 : 1010 1012 ... 

    5 : 10123 ...
    d[2][2] = d[1][1] + d[1][3]
    d[2][1] = 1 + d[1][2]
    d[2][9] = 1
    
    d[3][1] = 1 + d[2][2]
    d[3][2] = d[2][1] + d[2][3]

*/