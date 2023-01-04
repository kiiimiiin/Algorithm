#include <bits/stdc++.h>
using namespace std;
// 2중루프로 두명을 거짓난쟁이로 가정하고 뺐을때 100이면 거짓난쟁이

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int num[9], sum = 0;

    for(int i = 0 ; i < 9 ; i++) 
    {
        cin >> num[i];
        sum += num[i];
    }

    sort(num, num + 9);

    for(int i = 0 ; i < 8 ; i++)
    {
        for(int j = i + 1 ; j < 9 ; j++)
        {
            if( ( sum - num[i] - num[j]) == 100){
                for(int k = 0; k < 9; k++)
                if(k != i && k != j) cout << num[k] << '\n';
                return 0;
            }
        }
    }
}