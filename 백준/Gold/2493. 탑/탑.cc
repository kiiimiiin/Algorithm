#include <iostream>
#include <stack>
using namespace std;

int main(void){
    ios::sync_with_stdio(0), cin.tie(0);
    int n; 
    stack<pair<int,int>> s;
    s.push({100000001, 0}); // 벗어난 레이저를 처리하기 위함
    
    cin >> n;
    
    for(int i = 1 ; i <= n; i++){
        int height;
        cin >> height; 
        
        while( s.top().first < height){ // 앞에 탑이 낮음
            s.pop();
        }
        
        cout << s.top().second << ' '; // 앞에 탑이 높거나 같아 수신함 
        s.push({height, i});
    }
}

/*
    스택으로 탑을 하나 씩 처리 
    앞에 있는 탑이 높이가 낮다 -> 무시
    앞에 있는 탑이 높이가 높거나 같다 -> 수신 (수신 인덱스)
    
    높이와 수신 인덱스 필요
    
*/