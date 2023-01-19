#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    
    stack<char> S;
    string s;
    string yesOrNo;

    while(1)
    {  
        yesOrNo = "yes";
        getline(cin, s);
        if(s == ".") break;
        for(auto c : s)
        {
            if(c == '[' || c== '(')
                S.push(c);
            else if( c == ']' || c == ')')
                {
                    if(S.empty()) 
                    {
                        yesOrNo = "no";
                        break;
                    }
                    else if( c == ']')
                    {
                        if(S.top() != '[')
                        {
                            yesOrNo = "no";
                            break;
                        }
                        else S.pop();
                    }
                    else if( c == ')')
                    {
                        if(S.top() != '(')
                        {
                            yesOrNo = "no";
                            break;
                        }
                        else S.pop();
                    }
                }
        }
        if(!S.empty())
            yesOrNo = "no";
        std::cout << yesOrNo << '\n';
        while(!S.empty()) S.pop();
    }                
}