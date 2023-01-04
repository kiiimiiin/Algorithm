#include <bits/stdc++.h>
using namespace std;

int num, sum = 0, n = 7;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int min = 100;

   while(n--)
   {
        cin >> num;

        if ( num %2 != 0)
        {
            sum += num;
            min = num < min ? num : min;
        }
   }
   
   if(sum == 0) cout << -1 << '\n';
   else
    {
        cout << sum << '\n';
        cout << min << '\n';
    }
}