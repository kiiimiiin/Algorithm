#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX(a,b) (a > b ? a : b);
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int MX = 260000;

struct Pos {
    int x,y;
};

typedef struct Pos Pos;
Pos queue[MX];
int head, tail;

void push(Pos x){
    queue[tail++] = x;
}

void pop(){
    head++;
}

Pos front(){
    return queue[head];
}

bool IsEmpty(){
    return head == tail;
}




// land_rows는 2차원 배열 land의 행 길이, land_cols는 2차원 배열 land의 열 길이입니다.
int solution(int** land, size_t land_rows, size_t land_cols) {
    
    
    bool vis[502][502] = {};
    int cntByCul[502] = {};
    int visCurByCse[502] = {};
    
    for(int i = 0 ; i < land_rows; i++){
        for(int j = 0 ; j < land_cols; j++){
            if(vis[i][j] || land[i][j] == 0) continue;
            int area = 0;
            vis[i][j] = true;
            Pos pos; pos.x = i; pos.y =j;
            push(pos);
                
            while(!IsEmpty()){
                Pos cur = front(); pop(); area++;
                if(cntByCul[cur.y] >= 0)
                    cntByCul[cur.y] -= 10000000;
                for(int dir = 0 ; dir < 4; dir++){
                    int nx = cur.x + dx[dir];
                    int ny = cur.y + dy[dir];
                    if(nx < 0 || nx >= land_rows || ny < 0 || ny >= land_cols) continue;
                    if(vis[nx][ny] || land[nx][ny] == 0) continue;
                    vis[nx][ny] = true;
                    Pos nxt; nxt.x = nx; nxt.y =ny;
                    push(nxt);
                }
            }
            
            for(int k = 0; k <land_cols; k++){
                if(cntByCul[k] < 0) cntByCul[k] += 10000000 + area;
            }
        }
    }
    
    int answer = -0x7f7f7f7f;
    for(int k = 0; k <land_cols; k++){
        answer = MAX(answer, cntByCul[k]);
    }
    
    
    return answer;
}

/*
    bfs를 돌며 석유덩어리에 대한 열정보들 구함
    
    1번째 덩어리 8개 -> 1 2 3
    2번째 덩어리 7개 ->4 5 6 7
    3번째 덩어리 2개 -> 7 8
    
    열에대한 개수중 최대 개수를 구함 

*/ 