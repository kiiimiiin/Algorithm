#include <iostream>
using namespace std;
int n, k;
int arr[11];


int main(void){
    ios::sync_with_stdio(0), cin.tie(0);
    
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    
    
    int ans = 0;
    for(int i = n; i >= 0; i--){
        if( k == 0) break;
        ans += k / arr[i];
        k = k % arr[i];
    }
    cout << ans;
    
}