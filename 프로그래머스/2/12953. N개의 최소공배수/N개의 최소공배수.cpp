#include <string>
#include <vector>
using namespace std;

int getGCD(int n, int m){
    if(n % m == 0) return m;
    return getGCD(m, n % m);
}

int getLCM(int n, int m){
    return n * m / getGCD(n, m);
}

int solution(vector<int> arr) {
    int answer = arr[0];
    
    for(int i = 1; i < arr.size(); i++)
        answer = getLCM(answer, arr[i]);
    
    return answer;
}