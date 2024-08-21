#include <iostream>
#include <algorithm> 
using namespace std;
int d[1002];
int a[1002];
int n;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    
    cin >> n;
    
    for(int i = 0 ; i < n; i++){
        cin >> a[i];
        d[i] = a[i];
        for(int j = 0 ; j < i; j++){
            if(a[j] < a[i] && d[j] + a[i] > d[i]){
                d[i] = d[j] + a[i];
            }
        }
    }    

    cout << *max_element(d , d + n);
}

/*
    d[i] : i번째에서 증가하는 부분수열의 최대 합
*/
