#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    int len = s.length();
    int pCnt = 0, yCnt = 0;
    for(int i = 0 ;  i < len; i++){
        if( s[i] == 'p' || s[i] == 'P') pCnt++;
        else if(s[i] == 'y' || s[i] == 'Y') yCnt++;
    }

    return pCnt == yCnt ? true : false ;
}