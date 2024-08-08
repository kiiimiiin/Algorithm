#include <string>
#include <algorithm> 
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    
    for(int i = 0; i <= 9; i++){
        auto it = find(numbers.begin(), numbers.end(), i);
        if(it != numbers.end()) continue; 
        answer+= i; 
    }
    
    return answer;
}