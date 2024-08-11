#include <iostream>
#include <algorithm>
using namespace std;
int rope[100002];
int n;

int main(void){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    
    for(int i = 1 ; i <= n; i++)
        cin >> rope[i];
        
    sort(rope + 1, rope + n + 1, greater<int>());
    
    int mx = -0x7f7f7f7f;
    for(int i = 1 ; i <= n; i++){
        mx = max(mx, rope[i] * i);
    }
    
    cout << mx;
    
}

/*
    큰 로프를 택해나갈때 버티는 최대중량이라고 가정
    
    10, 15 택하면 10 씩가해짐
    5, 10 , 15 택하면 5씩가해짐
*/