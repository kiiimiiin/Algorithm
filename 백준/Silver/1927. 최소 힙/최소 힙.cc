#include <queue>
#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    priority_queue<int, vector<int>, greater<int>> pq;
    cin >> n;
    
    while(n--){
        int init;
        cin >> init;
        if(init){
            pq.push(init);
        } else{
            if(pq.empty())
                cout << "0\n";
            else{
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
    }
    
    return 0;
}