#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    
    int N, X;
    cin >> N >> X ;

    vector<int> A(N);

    for( int i = 0 ; i < N ;  i++)
        cin >> A[i];


    for( int i = 0 ; i < N ;  i++){
        if( A[i] < X)   cout << A[i] << " ";
       }
    
     return 0;
}