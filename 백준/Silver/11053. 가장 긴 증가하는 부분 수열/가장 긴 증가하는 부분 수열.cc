#include <iostream>
#include <algorithm>
using namespace std;
int a[1002];
int d[1002];
int n;

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    
    cin >> n;
    
    for(int i = 0 ; i < n; i++){
        cin >> a[i];
    }
    
    for(int i = 0 ; i < n; i++){
        d[i] = 1;
        for(int j = 0; j < i; j++){
            if(a[j] < a[i] && d[j] + 1 > d[i])
                d[i] = d[j] + 1;
        }
    }
    
    cout << *max_element(d, d + n);
    
}

/*
    d[i] : i번째 까지의 최대 증가하는 부분 수열 길이

*/