#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(int a, int b) {
    // 리턴할 값은 메모리를 동적 할당해주세요.
    char* answer = (char*)malloc(4);
    const char* whatDay[7] = {"THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"};
    int dateByMonth[13] = {-1, 31, 29, 31 , 30, 31, 30, 31, 31 , 30, 31, 30 , 31};
    
    int totalDate = b;
    for(int i = 1; i < a; i++){
        totalDate += dateByMonth[i];
    }
    
    strcpy(answer,whatDay[ totalDate % 7 ]);
    
    return answer;
}