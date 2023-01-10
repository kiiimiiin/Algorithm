#include <bits/stdc++.h>
using namespace std;
// 0 ~ 9 1set
// N : 1 ~ 1000000 자연수 , 필요한 set 수 ? 
// 6&9 필요 set수랑 원래 필요 set수랑 비교
// 6,9 3~4개 -> 2SET | 6,9 5~6개 -> 3SET

int countNum[11];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, sixNineSet;
    cin >> n;

    while(n) // 자릿수 count
    {
        countNum[ n % 10 ]++;
        n /= 10;
    }

    sixNineSet = (countNum[6] + countNum[9] + 1) / 2;
    countNum[6] = countNum[9] = 0;
    sort(countNum, countNum+10);

    if(sixNineSet > countNum[9]) cout << sixNineSet;
    else cout << countNum[9];
}