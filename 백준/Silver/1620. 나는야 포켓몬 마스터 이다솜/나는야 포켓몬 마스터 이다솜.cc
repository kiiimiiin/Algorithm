#include <iostream>
#include <unordered_map>
#include <string> 
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, m;
    unordered_map<string, int> s2i;
    string i2s[100002];
    
    cin >> n >> m;
    
    for(int i = 1 ; i <= n; i++){
        string name;
        cin >> name;
        
        s2i[name] = i;
        i2s[i] = name;
    }
    
    for(int i = 0 ; i < m; i++){
        string x;
        cin >> x;
        if(isdigit(x[0])){
            cout << i2s[stoi(x)] << '\n';
        }
        else{
            cout << s2i[x] << '\n';
        }
    }
}