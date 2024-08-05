#include <iostream>
#include <algorithm>
using namespace std; 
int n;
int num[1002], d[1002];

int main(){
    cin >> n;
    
    for(int i = 0; i < n; i++) cin >> num[i];
    
    for(int i = 0 ; i < n; i++){
        d[i] = 1;
        for(int j = 0; j < i; j++){
            if(num[j] < num[i] && d[j] + 1 > d[i]){
                d[i] = d[j] + 1;
            }
        }
    }
    
    cout << *max_element(d, d + n);
}


/*
    d[i] : i번째 수까지 증가하는 부분 수열의 최대 길이
    d[i]의 초기값 => 1 ( num[i]만을 택한다고 했을 떄)
    
    i보다 작은 j에 대해서
    단 , num[j] < num[i]
    d[j] + 1 > d[i]
    d[i] = d[j] + 1
    

*/