#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<long long> v;
int n , m;

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for(int i = 0 ; i < n; i++){
        int num; 
        cin >> num;
        v.push_back(num);
    }
    
    while(m--){
        sort(v.begin(), v.end(), greater<long long>());
        long long sum = v.back();
        v.pop_back();
        sum += v.back();
        v.pop_back();
        
        v.push_back(sum);
        v.push_back(sum);
    }
    
    long long ans = 0;
    for(auto num : v){
        ans += num;
    }
    cout << ans;
}

/*
   가장 작은 카드 두개를 택해서 덮어씌여 나감
    

*/