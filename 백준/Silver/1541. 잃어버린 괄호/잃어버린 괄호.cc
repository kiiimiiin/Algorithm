#include <iostream>
#include <string>
#include <cctype>
using namespace std;


int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    
    string s;
    string tmp = ""; 
    int ans = 0;
    cin >> s;
    
    bool isMinus = false;
    int len = s.length(); 
    for(int i = 0; i <= len; i++){
        if(!isMinus){
            if(!isdigit(s[i]) || s[i] == '\n'){
                ans += stoi(tmp);
                tmp = "";
                if(s[i] == '-')
                    isMinus = true ;
                continue;
            }
             
        }else{
            if(!isdigit(s[i]) || s[i] == '\n'){
                ans -= stoi(tmp);
                tmp = "";

                continue;
            }
        }


        tmp += s[i]; 
    }
    
    cout << ans; 
}

/*
   55+40-40+70-10+20
   ->
   55+40-(40+70)-(10+20) 해야 최소
   
*/