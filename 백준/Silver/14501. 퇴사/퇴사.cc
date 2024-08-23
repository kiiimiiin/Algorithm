#include <iostream>
#include <algorithm>
using namespace std;
int n;
int d[25], t[25], p[25];

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    
    for(int i = 1 ; i <= n; i++){
        cin >> t[i] >> p[i];
    }
    
    
    for(int i = n; i >= 1; i--){
        if(i + t[i] - 1 <= n)
            d[i] = p[i] + *max_element(d + i + t[i], d + n + 1);
        else
            d[i] = 0;
    }
    
    cout << *max_element(d + 1 , d + n + 1);
}

/*
    d[i] : i일의 최대 이익
    
    역순으로 순회

*/