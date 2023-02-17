#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> nArray;
int mArray[10];
bool isused[10002]; 
void backTracking(int idx) // 현재 수열의 길이, idx에 수를 놓을 차례
{
    if(idx == m)
    {
        for(int i = 0; i < m; i++)
            cout << mArray[i] << ' ';
        cout << '\n';
        return ;
    }
    
    for( int i : nArray)
    {
        if(idx == 0 || i > mArray[idx - 1])
        {
            if(isused[i]) continue;
            mArray[idx] = i;
            isused[i] = true;
            backTracking(idx + 1);
            isused[i] = false;
        }   
    }
}
int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        int init;
        cin >> init;
        nArray.push_back(init);
    }
    sort(nArray.begin(), nArray.end());
    backTracking(0);
}