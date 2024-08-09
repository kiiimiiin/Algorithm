#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
int n , t;
int rope[100002];

int main()
{
   cin >> n ;
   
   for( int i = 1 ; i <= n; i++){
       int rw;
       cin >> rw;
       rope[i] = rw;
   }
   
   sort(rope + 1, rope + n + 1, greater<int>()); 
   
   int mx = -0x7f7f7f7f;

   for(int i = 1; i <= n; i++){
       mx = max(mx, rope[i] * i );
   }
   
   cout << mx;
    
}

/*
    로프가 들어 올릴 수 있는 물체의 최대 중량
    k개 로프를 사용해 중량 w인 물체를 들어올릴 때 로프에는 고르게 w/k가 걸림
    
    11 12 13 일 때 최대 중량 -> 33 /3 = 11, 11 * 3 = 33
    
    큰 수 부터 작은수 순회, 현재까지 택한 수의 값과 로프개수를 곱
    
*/