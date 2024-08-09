#include <iostream>
using namespace std;
int n , k;
int arr[12];

int main()
{
   cin >> n >> k;
   
   for(int i = 1 ; i <= n; i++){
       cin >> arr[i];
   }
   
   int ans = 0; 
   for(int i = n; i >= 1; i--){
       if(arr[i] > k) continue;
       ans += k / arr[i]; 
       k %= arr[i];
   }
   
   cout << ans;
    
}

/*
    가정 ) 높은 금액의 동전을 최대한 많이 쓴다. 

*/