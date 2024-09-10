#include <string>
#include <vector>

using namespace std;

int getGcd(int a, int b){
    if(a % b == 0)  return b;
    return getGcd(b, a % b);
}

int getLcm(int a, int b, int gcd){
    return (a * b) / gcd;
}
vector<int> solution(int n, int m) {
    vector<int> answer;
    
    int gcd = getGcd(n, m);
    int lcm = getLcm(n, m, gcd);
    answer.push_back(gcd);
    answer.push_back(lcm);
    
    return answer;
}