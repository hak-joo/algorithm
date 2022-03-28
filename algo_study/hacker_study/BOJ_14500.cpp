#include <iostream>
using namespace std;

int board[505][505];
bool isVisited[505][505];

int dX[4] = {1,0,-1,0};
int dY[4] = {0,1,0,-1};

int N, M;
int res = -1;

void copy(bool origin[505][505], bool copied[505][505]){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            copied[i][j] = origin[i][j];
        }
    }
}

void func(int x, int y, int cnt, int sum){
    if(cnt == 4){
        res = max(res, sum);
        return;
    } else{
        for(int i=0; i<4; i++){
            int curX = x + dX[i];
            int curY = y + dY[i];
            if(curX < 0 || curX >= M || curY < 0 || curY >= N) continue;
            if(isVisited[curY][curX]) continue;
            isVisited[curY][curX] = true;
            func(curX, curY, cnt+1, sum+board[curY][curX]);
            isVisited[curY][curX] = false;
        }
    }
}

void func2(int x){
    for(int y=0; y<N; y++){
        //ㅓ
        if(0 <= x && x+1 < M && 0 <= y-1 && y+1 < N){
            res = max(res, board[y][x] + board[y-1][x+1] + board[y][x+1] + board[y+1][x+1]);
        }
        //ㅗ
        if (0 <= x-1 && x+1 <M && 0 <= y && y+1 < N){
            res = max(res, board[y][x] + board[y+1][x] + board[y+1][x-1] + board[y+1][x+1]);
        }
        //ㅏ
        if(0<= x && x+1 < M && 0<= y-1 && y+1 <N){
            res = max (res, board[y-1][x] + board[y][x] + board[y+1][x] + board[y][x+1]);
        }
        //ㅜ
        if (0<= x-1 && x+1 <M && 0 <= y && y+1 <N){
            res = max(res, board[y][x-1] + board[y][x] + board[y][x+1] + board[y+1][x]);
        }
    }
    
}

int main(void){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> board[i][j];
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            isVisited[i][j] = true;
            func(j,i,1,board[i][j]);
            isVisited[i][j] = false;
        }
    }
    for(int x=0; x<M; x++){
        func2(x);
    }
    cout << res;


}