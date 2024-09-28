#include <iostream>
#include <queue>
using namespace std;
int n; 

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    priority_queue<int> pq; 
    
    cin >> n;
    
    while(n--){
        int x;
        cin >> x;
        if(x != 0){
            pq.push(x);
        }
        else{
            if(!pq.empty()){
                cout << pq.top() << "\n";
                pq.pop();
            }
            else
                cout << "0\n";
        }
    }
}