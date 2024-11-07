#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


int compare(const void *a, const void *b){
    int *ap = (int *)a;
    int *bp = (int *)b;
    
    return (*ap - *bp); // asc 
}

int* solution(int k, int score[], size_t score_len) {

    int* answer = (int*)malloc(1002*sizeof(int));
    int winner[102];
    
    for(int i = 0; i < k; i++) 
        winner[i] = 0x7f7f7f7f;
    
    
    for(int i = 0; i < score_len; i++){
        if(i < k)
            winner[i] = score[i];
        else if (winner[0] < score[i])
            winner[0] = score[i];

        qsort(winner, k, sizeof(int), compare);
        answer[i] = winner[0];
        /*
        for(int i = 0 ; i < k; i++){
            printf("%d ", winner[i]);
        }
        printf("\n");        
        */
       
    }
    
    return answer;
}

/*

    100 0000
*/