#include <bits/stdc++.h>
using namespace std;
int counts[10];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    do{
        int one_digit = n % 10;
        counts[one_digit]++;
        if(one_digit == 9) counts[6]++;
    }while(n /= 10);

    if(counts[6] % 2 == 0) counts[6] = counts[6] / 2 ; // 짝수 
    else counts[6] = counts[6] / 2 + 1;
    int* max = max_element(counts, counts+9);
    cout << *max;
}