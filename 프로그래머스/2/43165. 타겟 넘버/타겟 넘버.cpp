#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int n = numbers.size();
    
    for(int cse = 0; cse < ( 1 << n ); cse++){
        
        int brute = cse;
        int val = 0;
        for(int idx = 0 ; idx < n; idx++){
            int isPlus = brute % 2;
            brute /= 2;
            if(isPlus)
                val += numbers[idx];
            else
                val -= numbers[idx];
        }
        
        if(val == target) 
            answer++;
    }
    return answer;
}