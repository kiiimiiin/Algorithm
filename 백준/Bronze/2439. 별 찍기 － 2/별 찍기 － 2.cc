#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    int n, j;
    cin >> n; // n번 반복

    for(int i = 1; i <= n; i++) //n번 출력 
    {
        for(int j = 0; j < n - i ; j++) cout << ' '; //별 제외 갯수
        for(int k = 0 ; k < i; k++) cout << '*'; // 별 갯수
        cout << '\n';
    }
}