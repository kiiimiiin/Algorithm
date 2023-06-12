#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    int a[5]; // 숫자 3개 받을 배열

    for(int i = 0 ; i < 3 ; i++) cin >> a[i];
    sort(a, a+3);
    for(int i = 0 ; i < 3 ; i++) cout << a[i] << ' ';
}