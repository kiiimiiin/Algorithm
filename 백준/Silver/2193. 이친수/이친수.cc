#include <iostream>
#include <algorithm>
using namespace std;
long long d[92][2]; // i번째 자리가 0, 1 일때 이친수 개수

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    
    d[1][0] = 0;
    d[1][1] = 1; 
    
    for(int i = 2; i <= n; i++){
        d[i][0] = d[i-1][0] + d[i-1][1];
        d[i][1] = d[i-1][0];
    }
    
    cout << d[n][0] + d[n][1];
    return 0;
}
