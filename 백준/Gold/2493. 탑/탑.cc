#include <iostream>
#include <utility>
#include <stack>
using namespace std;
 
int main(void){
    ios::sync_with_stdio(0), cin.tie(0);
    int n; 
    cin >> n;
    
    stack<pair<int,int>> S;
    S.push({100000001, 0}); 
    
    for(int i = 1 ; i <= n; i++){
        int height; // 현재 인덱스 탑 높이
        cin >> height; 
        
        while(S.top().first < height){ // 앞에 탑들과 높이비교
            S.pop(); 
        }
        
        cout << S.top().second << ' '; // 도달한 탑의 인덱스
        S.push({height, i}); // 현재 탑 추가
    }
}