#include <iostream>
using namespace std;

void swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
int main() 
{
    ios::sync_with_stdio(0), cin.tie(0);

    int a[4];
    
    for ( int i = 0 ; i < 3 ; i++)
        cin >> a[i];
    
    for ( int i = 0 ; i < 3; i++)
         for ( int j = i + 1 ; j < 3 ; j++)
                if( a[j] < a[i]) swap(a[i], a[j]);

    for (int i = 0  ; i < 3 ; i++)
        cout << a[i] << " ";
}
