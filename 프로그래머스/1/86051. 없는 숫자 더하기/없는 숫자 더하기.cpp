#include <string>
#include <algorithm> 
#include <vector>
using namespace std;
int arr[10];

int solution(vector<int> numbers) {
    int answer = 0;
    for(auto n : numbers){
        arr[n] = true;
    }
    
    for(int i = 0 ; i <= 9; i++){
        if(arr[i] == false) answer += i;
    }
    
    return answer;
}