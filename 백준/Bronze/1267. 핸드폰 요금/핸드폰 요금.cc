#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    //영식요금제: 0~29 +10원 30~59 +10원
    // 30으로 나눌 때 몫 0       1
    //민식요금제: 0~59 +15원 60~119 +15원
    // 통화수, 이에 따른 통화 시간 입력받음 
    // 시간에 따른 요금제 비용 총합을 비교

    int callNum, callTime, ySum=0 , mSum= 0;

    cin >> callNum;

    while(callNum--)
    {
        cin >> callTime;

        ySum += 10 * ( callTime / 30 + 1 );
        mSum += 15 * ( callTime / 60 + 1 );
    }

    if( ySum > mSum) cout << "M " << mSum;
    else if( ySum < mSum) cout << "Y " << ySum;
    else cout << "Y M " << ySum;
}