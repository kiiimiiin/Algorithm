#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    // int : 21 * 10^8 
    long long a , b ;

    cin >> a >> b ;

    if ( a == b || abs(a-b) == 1 )   cout << "0" ;
    else
    {

        cout << max(a,b) - min(a,b) - 1 << '\n';
        for(long long i = min(a,b) + 1; i < max(a,b) ; i++) cout << i << " ";
    }
}