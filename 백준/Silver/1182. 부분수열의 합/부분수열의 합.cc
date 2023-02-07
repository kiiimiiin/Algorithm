#include <bits/stdc++.h>
using namespace std;
 // 모든 후보군을 다 탐색하는 알고리즘 (백트래킹)
 int n, s, cnt;
 int arr[25]; 

void backTracking(int t, int cur) // t는 현재 부분 수열의 총합, cur는 원소를 택한 횟수
{
    if(cur == n) // 원소가 끝까지 갔을 때 종료
    {
        if( t == s) cnt++; // 이때 합이 s와 같아야함
        return ;
    }
    
    backTracking( t , cur + 1);
    backTracking( t + arr[cur], cur + 1);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> s;
    for(int i = 0; i < n; i++) cin >> arr[i];

    backTracking(0, 0); 
    if(s == 0) cout << cnt - 1 ;
    else cout << cnt ; // 크기가 양수인 부분수열이므로 공집합은 제외됨.
}