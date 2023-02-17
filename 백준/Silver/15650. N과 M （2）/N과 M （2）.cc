#include <bits/stdc++.h>
using namespace std;
int n,m ;
int arr[10];
int main()
{
    cin >> n >> m;
    fill(arr + m, arr + n, 1); // m개를 택함 
    do{
        for(int i = 0; i < n ; i++)
        {
            if(arr[i] == 0)
            cout << i + 1 << ' ';
        }
        cout << '\n';
    }while(next_permutation(arr, arr+n));
}