#include <iostream>
#include <algorithm>
#define END first
#define START second
using namespace std;
int n;
vector<pair<int,int>> disc;


int main(void){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    
    for(int i = 0 ; i < n; i++){
        int end, start;
        cin >> start >> end;
        disc.push_back({end, start});         
    }
    
    sort(disc.begin(), disc.end());
    
    int t = 0, ans = 0;;
    for(int i = 0 ; i < disc.size(); i++){
        if(disc[i].END >= t && disc[i].START >= t){
            t = disc[i].END;
            ans++;
        }
    }
    
    cout << ans;
    
}

/*
    끝나는 시간이 짧은 회의들을 택해 나갈 때 회의의 최대개수가 될 것이다. 
    시작시간도 오름차순 정렬을 해야하는 이유는 (1,2) (2,2) 같이 시작시간과 
    끝나는 시간이 같은 경우때문이다
*/