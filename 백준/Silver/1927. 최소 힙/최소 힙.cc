#include <queue>
#include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(0), cin.tie(0);
    int n, x;
    priority_queue<int, vector<int>, greater<int>> pq; // 최소힙
    
    cin >> n;
    
    for(int i = 0 ; i <  n; i++){
        cin >> x;
        if(x != 0) pq.push(x);
        else{
            if(!pq.empty()){
                cout << pq.top() << '\n';
                pq.pop();
            }
            else{
                cout << "0\n";
            }
        }
    }
}