#include <string>
#include <vector>

using namespace std;

int getGcd(int a, int b){
    if(a % b == 0) return b;
    return getGcd(b, a % b);
}

int getLcm(int a, int b){
    return ( a * b) / getGcd(a, b); 
}
int solution(vector<int> arr) {
    int answer = arr[0];
    
    for(int i = 1 ; i < arr.size(); i++){
        answer = getLcm(answer, arr[i]);
    }
    
    return answer;
}