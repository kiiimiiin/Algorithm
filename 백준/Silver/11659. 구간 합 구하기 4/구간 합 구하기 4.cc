#include <iostream>
using namespace std; 
int s[100002];
int nums[100002]; 

int main(void){
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;

    cin >> n >> m;
    
    for(int i = 1 ; i <= n; i++){
        cin >> nums[i];        
        s[i] = s[i-1] + nums[i];
    }
    
    while(m--){
        int i, j; 
        cin >> i >> j;
        cout << s[j] - s[i-1] << '\n';
    }
    
}

/*
    시간복잡도로 인해 선형합으로 구할 수 없음 
    
    i번째 수까지 합 d[i]
    j번째 수까지 합 d[j]
    i~j번째 수까지 합 d[j] - d[i-1]
*/