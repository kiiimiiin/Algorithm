#include <bits/stdc++.h>
using namespace std;
// 1 ~ 6 학년, 동일학년 동일성별 방배정
// 학생수 N 1~1000 | 방배정 최대인원수 K 1~1000
// S (0 여 , 1 남) | 학년 Y (1 ~ 6)
// 같은학년 같은성별의 학생수를 COUNT할 배열 필요

int man[7], girl[7];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n, k, s, y, cnt=0;
    cin >> n >> k;

    while(n--)
    {
        cin >> s >> y;
        if(s) man[y]++;
        else girl[y]++;
    }

    for(int i = 1; i <= 6; i++) // 1 -> 1개 , 2 -> 1개 , 3 -> 2개
         cnt += ( man[i] + 1 ) / 2 + (girl[i] + 1 ) / 2;
    cout << cnt;
}
    