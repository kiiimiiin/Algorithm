#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, t, x;


int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    
    cin >> t;
    
    while(t--){
        vector<int> price; 
        cin >> n; 
        for(int i = 0 ; i < n; i++){
            cin >> x;
            price.push_back(x);
        }
        
        long long sum = 0;
        int mx = -0x7f7f7f7f;
        
        for(int i = price.size() - 1; i >= 0; i--){
            if(price[i] > mx)
                mx = price[i];
            else
                sum += mx - price[i];
        }
        
        cout << sum << '\n';
    }
}

/*

    1 1 7 5 2 7 9 / 1 5 6 7 8 
    
    최대 인덱스까지 짜르고, 이익을 구해나감
    
    -> 역순으로 구하면 O(N)에 가능

*/