#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dX[5] = {0, 1, 0 ,-1 , 0};
int dY[5] = {0, 0, 1, 0, -1};

int board[15][15];
int price[15][15];
int impossible[15][15];
int mn = 2147483647;
int N;

void copy(int origin[15][15], int copied[15][15]){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            copied[i][j] = origin[i][j];
        }
    }
}

void calc(){
    int res = 0;
    for(int y=0; y<N; y++){
        for(int x = 0; x <N; x++){
            if(board[y][x] == 1){
                for(int i=0; i<5; i++) {
                    res += price[y+dY[i]][x+dX[i]];
                }
            }
        }
    }
    mn = min(mn, res);
}

bool check(int y, int x){

    if(y==0 || y == N-1 || x == 0 || x == N-1) return false; //사이드는 아예 못 들어감
    
    for(int i=1; i<5; i++){ // 상하좌우만 검사
        int cX = dX[i] + x;
        int cY = dY[i] + y;
        if(impossible[cY][cX]) return false;
    }
    return true;
}


void bfs(int y, int cnt){
    int copied[15][15];
    int p_copied[15][15];
    
    if (cnt == 3){
        calc();
        return;
    } else {
        for(int i = y; i<N; i++){
            for(int x = 1; x<N; x++){
                if(check(i, x)){
                    copy(board, copied);
                    copy(impossible, p_copied);
                    
                    board[i][x] = 1;
                    for(int k=0; k<5; k++){
                        impossible[i+dY[k]][x+dX[k]] = 1;
                    }

                    bfs(y, cnt+1);
                    copy(copied, board);
                    copy(p_copied, impossible);
                }
            }
        }
    }
}

int main(void){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    for(int y=0; y<N; y++){
        for(int x=0; x<N; x++){
            cin >> price[y][x];
        }
    }

    bfs(1,0);

    cout << mn;


}