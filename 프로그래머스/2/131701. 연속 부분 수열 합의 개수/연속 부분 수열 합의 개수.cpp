#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    set<int> S;

    int n = elements.size();

    for (int i = 0 ; i < n ; ++i) {
        int sum = 0;
        for (int j = i ; j < i + n ; ++j) {
            sum += elements[j % n];
            S.insert(sum);
        }
    }

    return S.size();
}