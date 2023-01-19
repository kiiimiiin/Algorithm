#include <bits/stdc++.h>
using namespace std;

// 10 3
// 1 2 3 -> 1 1 1 , 총 0번 
// 2 9 5 
// 1 2 3 4 5 6 7 8 9 10
// 2를 뽑으려면 3 -> 1 
// 3 4 5 6 7 8 9 10 1 
// 9를 뽑으려면 2 2 2 -> 1 
// 1 10 3 4 5 6 7 8
// 5를 뽑으려면 2 2 2 2 -> 1 , 총 8번
// 양 방향에서 삭제하고 추가하여야 하므로 deque

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    
    deque<int> DQ;
    int n, m, pos, cnt = 0;
    int twoCnt, threeCnt; // 특정 원소를 front에 위치하는데 드는 연산 cnt
    cin >> n;
    for(int i = 1; i<= n; i++) DQ.push_back(i);
    
    cin >> m;
    while(m--)
    {
        cin >> pos;
        auto it = find(DQ.begin(), DQ.end(), pos);
        twoCnt = it - DQ.begin();
        threeCnt = DQ.end() - it;
        if(twoCnt < threeCnt) // 최솟값이므로 작은 연산을 실행
        {
            while(DQ.front()!=pos)
            { //원소가 front가 될때 까지 2번 연산 실행
                DQ.push_back(DQ.front());
                DQ.pop_front();
                cnt++;
            }   
        }
        else
        {
            while(DQ.front()!=pos)
            { // 3번 연산
                DQ.push_front(DQ.back());
                DQ.pop_back();
                cnt++;
            }
        }
        DQ.pop_front(); // 원소가 front에 위치하기까지 count하고 지움 
    }
    cout << cnt << '\n';
}