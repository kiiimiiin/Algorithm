#include <iostream>
#include <algorithm>
using namespace std;
int d[100002]; // i번째 수 까지 합

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m ;
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++){
        int num;
        cin >> num;
        d[i] = d[i-1] + num;
    }
    
    while(m--){
        int left, right;
        cin >> left >> right;
        cout << d[right] - d[left - 1] << '\n';
    }
    return 0;
}