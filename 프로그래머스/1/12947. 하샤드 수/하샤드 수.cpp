#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
 
    int tmp = x;
    int sum = 0;
    while(tmp){
        sum += tmp % 10;
        tmp /= 10; 
    }

    return x % sum == 0 ? true : false;
}