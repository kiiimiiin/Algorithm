#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
int board[10][10];
int detectedBoard[10][10]; 
int n , m, emptyMin = 100;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1}; // 남동북서
vector<pair<int,int>> cctv; // cctv의 정보

void boardCopy(int desc[10][10], int src[10][10])
{
    for(int i = 0 ; i < n ; i++)
        for(int j = 0; j < m ; j++)
            desc[i][j] = src[i][j];
} 

void cctvDetect(int dir, int detectX, int detectY)
{ // 해당 방향으로 cctv 감시
    dir %= 4;
    while(1)
    {
        detectX += dx[dir];
        detectY += dy[dir];
        if(detectX < 0 || detectX >= n || detectY < 0 || detectY >= m ) break;
        if(detectedBoard[detectX][detectY] == 6) break;
        if(detectedBoard[detectX][detectY] != 0) continue;
        detectedBoard[detectX][detectY] = 7; // 감시표시
    }
}
int main()
{
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m; j++)
        {
            cin >> board[i][j];
            if(board[i][j] != 0 && board[i][j] != 6) cctv.push_back({i,j}); // cctv 정보 수집
        }
    }
    
    for(int tmp = 0 ; tmp < (1<<(2*cctv.size())) ; tmp++) // cctv의 방향에 대한 모든 경우 확인
    {
        int brute = tmp; // tmp값은 고정되어야 하므로 새로운 변수로 방향 정보를 추출
        boardCopy(detectedBoard, board); // 경우마다 빈 영역을 확인할 board생성
        for(int i = 0; i < cctv.size(); i++)
        { // 해당 경우의 각 cctv 순회
            int dir = brute % 4;
            brute /= 4;   
            int x , y;
            tie(x, y) = cctv[i];
            if(board[x][y] == 1)
            {
                cctvDetect(dir, x, y);
            }
            else if(board[x][y] == 2)
            {
                cctvDetect(dir, x, y);
                cctvDetect(dir + 2, x, y); 
            }
            else if(board[x][y] == 3)
            {
                cctvDetect(dir, x, y);
                cctvDetect(dir+1, x, y);
            }
            else if(board[x][y] == 4)
            {
                cctvDetect(dir, x, y);
                cctvDetect(dir+1, x, y);
                cctvDetect(dir+2, x, y);
            }
            else
            {
                cctvDetect(dir, x, y);
                cctvDetect(dir+1, x, y);
                cctvDetect(dir+2, x, y);
                cctvDetect(dir+3, x, y);
            }
        }    
        int emptyNum = 0;
        for(int i = 0 ; i < n; i++)
        for(int j = 0; j < m; j++)
            if(detectedBoard[i][j] == 0) emptyNum++; 
        emptyMin = min(emptyMin, emptyNum);       
    } // 모든 경우를 확인하며 빈공간의 최소수를 찾음
    cout << emptyMin ;
}