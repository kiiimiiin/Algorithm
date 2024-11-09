#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int getNxt(int num, int n){
    return num % n;
}
int solution(vector<int> elements) {
    int answer = 0;
    int n = elements.size();
    unordered_set<int> s;
    for(int len = 1; len <= n; len++){
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = 0; j < len; j++){
                int nxt = getNxt(i + j, n);
                sum += elements[nxt];
            }
            s.insert(sum);
        }
    }
    answer = s.size();
    return answer;
}

/*
    O(100만)
*/