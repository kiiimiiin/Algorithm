#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    string alpha = "abcdefghijklmnopqrstuvwxyz"; // str.length()
    string s;
    int arr[alpha.length()];

    fill(arr, arr + alpha.length(), 0);

    cin >> s;

    for(int i = 0; i < s.length(); i++)
    {
        for(int j = 0; j< alpha.length(); j++)
            if (s[i] == alpha[j]) arr[j] += 1;
    }

    for(int i = 0 ; i < alpha.length(); i++)
        cout << arr[i] << ' ';
}