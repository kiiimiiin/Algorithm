#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

   // 1 ~ 20 배열 , 구간 입력받으면 해당 구간 역순 배치
   // 마지막 카드 배치 출력

   int arr[25] = {}, tempArr[25] = {};
   int a, b ;
   
   for(int i = 1; i < 21; i++) arr[i] = i;
   for(int i = 0; i < 10; i++)
   {
    cin >> a >> b ;
    int dis = 0;
        for(int i = a; i <= b; i++) 
        {   
            tempArr[i] = arr[b - dis];
            dis++;
        } 

        for(int i = a; i<= b; i++)
        {
            arr[i] = tempArr[i];  
        }
   }
   for(int i = 1; i < 21; i++) cout << arr[i] << " ";
}