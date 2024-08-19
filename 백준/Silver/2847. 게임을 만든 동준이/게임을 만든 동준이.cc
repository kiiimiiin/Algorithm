#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int arr[102];

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    
    cin >> n;
    
    for(int i = 0; i < n; i++)
        cin >>  arr[i];
        
        
    int base = arr[n - 1];
    int ans = 0;
    for(int i = n - 2; i >= 0; i--){
        if(arr[i] >= base){
            ans += arr[i] - (base - 1);
            arr[i] = base - 1;
        }
        base = arr[i];
    }
    
    cout << ans;
}

/*

    역순으로 앞값보다 크면 그만큼 낮춤

*/