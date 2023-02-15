#include <bits/stdc++.h>
using namespace std;
// CCTV가 주어지고 CCTV에는 고유 방향이 존재
// 각 방향에 대한 모든 경우를 확인 Backtraking
// 복잡도 4^8 * 64 << 1억 -> ok
int n , m, emptyMin = 68;
int board[10][10];
int dirInfo[5] = {4, 2, 4, 4, 1};
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<tuple<int,int,int>> cctv; // cctv type , x, y 

void boardCopy(int desc[10][10], int src[10][10])
{
    for(int i = 0; i < n ; i++)
        for(int j = 0 ; j < m ; j++)
            desc[i][j] = src[i][j];
}

void cctvDetect(int dir, int cctvX, int cctvY)
{ //dir 한 방향 감시
    dir %= 4 ;
    int detectedX = cctvX;
    int detectedY = cctvY;
    while(1)
    {
        detectedX += dx[dir];
        detectedY += dy[dir];
        if(detectedX < 0 || detectedX >= n || detectedY < 0 || detectedY >= m) break;
        if(board[detectedX][detectedY] == 6) break; // 벽이거나 외부로 나가면 종료
        if(board[detectedX][detectedY] != 0) continue;
        board[detectedX][detectedY] = 7; // 감시표시
    }
}
void backTracking(int cctvNum) // cctv 확인 수
{
    if(cctvNum == cctv.size())
    {   
        int emptyNum = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0 ; j < m; j++)
                if(board[i][j] == 0) emptyNum++;
        emptyMin = min(emptyMin, emptyNum);
        return ;
    } // 경우마다 빈공간 확인 ( cctv 확인 수가 cctv 갯수랑 같아질 때가 종료조건)

    int cctvType, cctvX, cctvY;
    tie(cctvType, cctvX, cctvY) = cctv[cctvNum];
    for(int dir = 0 ; dir < dirInfo[cctvType - 1] ; dir++)
    {
        int tmp[10][10];
        boardCopy(tmp , board);
        if(cctvType == 1)
        {
            cctvDetect(dir, cctvX, cctvY);
        }
        if(cctvType == 2)
        {
            cctvDetect(dir, cctvX, cctvY);
            cctvDetect(dir + 2, cctvX, cctvY);
        }
        if(cctvType == 3)
        {
            cctvDetect(dir, cctvX, cctvY);
            cctvDetect(dir + 1, cctvX, cctvY);
        }
        if(cctvType == 4)
        {
            cctvDetect(dir, cctvX, cctvY);
            cctvDetect(dir + 1, cctvX, cctvY);
            cctvDetect(dir + 2, cctvX, cctvY);
        }
        if(cctvType == 5)
        {
            cctvDetect(dir, cctvX, cctvY);
            cctvDetect(dir + 1, cctvX, cctvY);
            cctvDetect(dir + 2, cctvX, cctvY);
            cctvDetect(dir + 3, cctvX, cctvY);
        }
        backTracking(cctvNum + 1);
        boardCopy(board, tmp);
    }
    
}

int main()
{
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            cin >> board[i][j];
            if(board[i][j] != 0 && board[i][j] != 6) // cctv정보 추출
                cctv.push_back({board[i][j], i, j});
        }
    }
    backTracking(0);
    cout << emptyMin; 
}