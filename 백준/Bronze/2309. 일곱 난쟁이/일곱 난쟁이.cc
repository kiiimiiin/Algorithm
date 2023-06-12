#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int height[9], sum = 0;
    for(int i = 0; i < 9; i++)
    {
        cin >> height[i];
        sum += height[i];
    }  
    
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(i != j && sum - ( height[i] + height[j]) == 100)
            {
                height[i] = height[j] = 100;
                sort(height, height + 9);
                for(int k = 0; k < 7; k++)  cout << height[k] << '\n';
                return 0;
            }
        }
    }
}