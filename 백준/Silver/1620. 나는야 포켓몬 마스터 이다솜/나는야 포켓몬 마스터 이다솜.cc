#include <iostream>
#include <unordered_map>
#include <string>
#include <cctype> // isdigit
using namespace std;

int main(void){
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, m;
    string s;
    unordered_map<string, int> dict_s;
    unordered_map<int, string> dict_i;
    
    cin >> n >> m;
    
    for(int i = 1 ; i <= n ; i++){
        
        cin >> s;
        dict_s[s] = i;
        dict_i[i] = s;
    }
    
    for(int i = 0; i < m; i++){
        string init;
        cin >> init;
        if(isdigit(init[0])){
            int num = stoi(init);
            cout << dict_i[num] << '\n';
        }
        else{
            cout << dict_s[init] << '\n';
        }
        
    }
}