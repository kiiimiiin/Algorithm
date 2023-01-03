#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    int a, b, c ;

    cin >> a >> b >> c ;

    if( a == b && b == c ) // a = b = c 인 경우
        cout << 10000 + a * 1000 ;
    else if ( a == b || b == c || c == a) // 두 수 같은 경우
       {// 두 줄 이상은 block 처리
        if(a==b || c == a) cout << 1000 + a*100;
        else if(b == c) cout << 1000 + b*100;
       } 
    else // 모든 수 다른 경우
        cout << max({a,b,c})* 100;
}