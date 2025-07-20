#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

bool solution(vector<string> phone_book) {
    unordered_set<string> s(phone_book.begin(), phone_book.end());
    
    for(auto phone : phone_book)
        for(int i = 0 ; i < phone.length(); i++)
            if(s.find(phone.substr(0, i)) != s.end())
                return false;

    return true;
}

// O(2000)