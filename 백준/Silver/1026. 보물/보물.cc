#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
int n , t;
int a[52];
int b[52];

int main()
{
   cin >> n;
   
   for(int i = 0; i < n; i++){
	   cin >> a[i];
   }
   
   for(int i = 0; i < n; i++){
	   cin >> b[i];
       
   }
   
    sort(a, a + n, greater<int>()); 
    sort(b, b + n);
    
    
    int s = 0;
    for(int i = 0 ; i < n; i++){
        s += a[i] * b[i]; 
    }
    cout << s;
}

/*

	2 7 8 3 1
	
	1 1 0 1 6 
  
    a의 가장 큰애들이 b의 작은애들과 매칭되야함
  
*/