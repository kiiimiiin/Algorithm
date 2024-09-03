#include <iostream>
#include <algorithm>
using namespace std;
int a[500005], b[500005];
int na, nb;


int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    vector<int> finded;
    cin >> na >> nb;
    for(int i = 0; i < na; i++)
        cin >> a[i];
    for(int i = 0; i < nb; i++)
        cin >> b[i];

    sort(b, b + nb);
    
    for(int i = 0 ; i < na; i++){
        if(!binary_search(b, b + nb, a[i])){
            finded.push_back(a[i]);
        }
    }
    
    sort(finded.begin(), finded.end());
    
    cout << finded.size() << '\n';
    
    for(auto x : finded)
        cout << x << ' ';
            
}

