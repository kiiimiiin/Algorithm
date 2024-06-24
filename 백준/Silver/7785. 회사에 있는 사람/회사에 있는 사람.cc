#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;

int main(void){
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    unordered_set<string> s; 
    
    cin >> n; 
    
    for(int i = 0; i < n; i++){
        string name, flag; 
        
        cin >> name >> flag;
        
        if(flag == "enter") s.insert(name);
        else s.erase(name);
    }
    
    vector<string> answer(s.begin(), s.end());
    sort(answer.begin(), answer.end(), greater<string>());
    // grater이면 사전순의 역순임  o p q r s t .. 
    
    for(auto e : answer){
        cout << e << '\n';
    }
}