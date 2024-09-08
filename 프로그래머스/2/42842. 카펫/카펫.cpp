#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int area = brown + yellow;
    
    for(int r = 3;;r++){ 
        if(area % r) continue;
        int c = area / r; 
        if(yellow == (r - 2) * (c - 2)){
            answer.push_back(c);
            answer.push_back(r);
            break;
        } 
    }
    return answer;
}
