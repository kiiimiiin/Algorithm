#include <bits/stdc++.h>
using namespace std;

// 키보드의 모든 명령 기록 : 알파벳 대문자, 소문자, 숫자 , bsp, 화살표
//1. 테스트 갯수 2. 길이 L 문자열 
// '-' : 커서앞  글자 지움 
// '<' '>' : 커서 위치변경
// 커서의 위치가 줄의 마지막이 아니면 
// .A : 한 set
// B. -> BP. -> BA.P -> BAP. -> BAPC.->BAPCd. -> BAPC.

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    int num;
    string init, rightString;
    list<char> charList; // end() == begin()
    cin >> num;

    while(num--)
    {
        cin >> init;
        auto cursor = charList.end();
        
        for(auto c : init)
        {
            if( c == '<')
            {
                if( cursor != charList.begin() )
                    cursor--;
            }
            else if( c == '>')
            {
                if(cursor != charList.end())
                    cursor++;
            }
            else if( c == '-')
            {
                if(cursor != charList.begin())
                    {
                        cursor--;
                        cursor = charList.erase(cursor);
                    }
            }
            else
            {
                   charList.insert(cursor, c);
            }
        } // 입력에 따른 커서이동 & 출력

    for (auto c : charList) cout << c ;
    cout << '\n';
    charList.clear();
    }   
}