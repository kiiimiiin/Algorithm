#include <queue>
#include <iostream>
using namespace std;


int main(void){
    ios::sync_with_stdio(0), cin.tie(0);
    int n, x;
    priority_queue<int, vector<int>, greater<int>> pq; // 최소힙
    
    cin >> n;
    for(int i = 0 ; i < n * n; i++){
        cin >> x;
        pq.push(x);
        if(n < pq.size()) pq.pop();
    }
    
    cout << pq.top(); 

}