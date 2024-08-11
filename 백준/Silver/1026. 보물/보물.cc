#include <iostream>
#include <algorithm>
using namespace std;
int a[52], b[52];
int n;


int main(void){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i = 0 ; i < n; i++) cin >> a[i];
    for(int i = 0 ; i < n; i++) cin >> b[i];
    sort(a, a + n);
    sort(b, b + n, greater<int>());
    
    int ans = 0;
    for(int i = 0 ; i < n; i++)
        ans += a[i] * b[i];
    
    cout << ans;
}

/*
    a와 b를 곱해서 최소값 s구하기
    a의 작은수와 b의 큰수를 매핑
*/