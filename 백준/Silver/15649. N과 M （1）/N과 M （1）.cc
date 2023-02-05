#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[10];
int isused[10];

void func(int k) // k개 택함
{
    if(k == m) // 리스트에 m개 존재
    {
        for(int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return ;
    } // base condition

    for(int i = 1 ; i <= n ; i++) // 리스트에 원소를 집어넣음
    {
        if(!isused[i]) // 사용안한 원소 , 1
        {
            arr[k] = i; // 1 2
            isused[i] = true;
            func(k+1); // k+1개 택함 , 1 2 3 1 2 4 
            isused[i] = false; // 1 2 의 경우 모두 확인 
        }
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    func(0);
}