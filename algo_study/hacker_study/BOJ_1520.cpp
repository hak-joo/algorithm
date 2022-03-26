#include <iostream>

using namespace std;

int M, N;
int arr[505][505];
int res;
int dX[4] = {1,0,-1,0};
int dY[4] = {0,1,0,-1};
int DP[505][505] = {-1};

int func(int y, int x){
    if(DP[y][x] != - 1) return DP[y][x];
    if(y == M-1 && x == N-1) return 1;

    DP[y][x] = 0;

   for(int dir=0;dir<4;dir++)
    {
        int curY = y + dY[dir];
        int curX = x + dX[dir];
        if(0 <= curY && curY <M && 0<= curX && curX < N){
            if(arr[y][x] > arr[curY][curX]){
                if(DP[curY][curX] != -1){
                    DP[y][x] += DP[curY][curX];
                } else{
                    DP[y][x] += func(curY,curX);
                }
            }
        }
    }

    return DP[y][x];
}

int main(void){
    cin.tie(0);
    cout.tie(0);    
    ios::sync_with_stdio(0);

    cin >> M >> N;
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
            DP[i][j] = -1;
        }
    }
    res = func(0,0);
    cout<<res;
}