#include <bits/stdc++.h>
using namespace std;

// a1~ an : 1<= n <= 100000
// 1 <= a <= 1000000
// 1 <= x <= 2000000

int a[100005], n, x; 
int countNum[1000005]; //count 배열
int setNum = 0;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++)  
    {
        cin >> a[i];
        countNum[a[i]]++;
    }
    cin >> x;
    for(int i = 1; i <= n; i++) 
        if((x - a[i] > 0 && x - a[i] < 1000005) && countNum[x - a[i]]) 
        setNum++;
    setNum /= 2;
    cout << setNum; // 중복을 제외
}