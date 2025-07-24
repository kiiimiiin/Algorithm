#include <iostream>
#include <algorithm>
using namespace std;
int d[502][502]; // fibonacci(i)일 때 0, 1 출력 수

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            int num;
            cin >> num;
            d[i][j] = max( d[i-1][j] , d[i-1][j-1] ) +  num;
        }
    }
    
    cout << *max_element(d[n] , d[n] + n + 1);
    return 0;
}

/*
    d[4][3] = d[3][3] + d[3][2]
    
    d[i][j] : i번째 층에서 j번째 수를 택했을 때 까지의 경로 합
    d[i][j] = d[i-1][j]  + d[i-1][j-1]; 
    
*/