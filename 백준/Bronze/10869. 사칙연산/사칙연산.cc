#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    
    int a, b;

    cin >> a >> b;
    cout << a+b << "\n" << a-b << "\n" << a*b << "\n"
    << a/b << "\n" << a%b << "\n" ;

    // / -> 정수나누기 (몫)
    // % -> 나머지
}