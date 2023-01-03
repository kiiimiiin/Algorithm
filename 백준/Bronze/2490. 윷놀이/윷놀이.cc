#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

   int a[5];
   int n = 3;
   while(n--){
    int cnt = 0;

    for(int i = 0; i < 4; i++){
    cin >> a[i];
    if(a[i] == 0) cnt++;
   }
   
    if(cnt == 1) cout << "A\n";
    else if(cnt == 2) cout << "B\n";
    else if(cnt == 3) cout << "C\n";
    else if(cnt == 4) cout << "D\n";
    else if(cnt == 0) cout << "E\n";
    }
}