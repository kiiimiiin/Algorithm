#include <bits/stdc++.h>
using namespace std;
int isused1[40]; // y
int isused2[40]; // x+y
int isused3[40]; // x-y+n-1

int cnt = 0;
int n;
void func(int cur) // cur행에 퀸을 두는 함수
{
    if(cur == n)
    {
        cnt++;
        return ;
    }
    for(int i = 0; i < n; i++)
    {
        if(isused1[i] || isused2[cur+i] || isused3[cur-i+n-1]) // 존재한 퀸의 공격범위 내
            continue;
        isused1[i] = 1; 
        isused2[cur+i] = 1;
        isused3[cur-i+n-1] = 1;
        func(cur+1); // 다음 행에 퀸을 둠 
        isused1[i] = 0;
        isused2[cur+i] = 0;
        isused3[cur-i+n-1] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    func(0);
    cout << cnt;
}