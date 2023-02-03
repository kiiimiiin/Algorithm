#include <bits/stdc++.h>
using namespace std;
//기저: 원판이 1개일 때 a에서 b로 옮길 수 있다
//일반화: 원판이 k개 일때 옮길수 있다면 k+1개일 때 옮길 수 있다. 
//함수: 원판 n개에 대해서 a에서 b로 옮기는 과정을 출력하는 함수
void hanoi(int n, int a, int b)
{
    if(n == 1) 
    {
        cout << a << ' ' << b << '\n';
        return ;
    } // base condition
    hanoi(n-1, a, 6-a-b);
    cout << a << ' ' << b << '\n';
    hanoi(n-1, 6-a-b, b);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    cout << (1<<n)-1 <<'\n';
    hanoi(n, 1, 3);
}