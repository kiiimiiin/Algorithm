#include <iostream>
#include <algorithm>
using namespace std;
int p[1002];
int n;

int main(void){
    cin >> n; 
    for(int i = 0; i < n; i++) cin >> p[i];
    
    sort(p, p + n);
    
    int ans = 0;
    int t = 0;
    for(int i = 0 ; i < n; i++){
        ans += t + p[i];
        t += p[i];
    }
    cout << ans;
}


/*
    인출 시간이 작은 순으로 
    인출하는데 걸리는 시간들을 합해 나감
*/