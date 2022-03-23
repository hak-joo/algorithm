#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int board[10][10];

vector<pair<int, int>> virused;

int dX[4] = {1, 0, -1, 0};
int dY[4] = {0, 1, 0, -1};
int mx = -1;
int N, M;

void copy (int origin[10][10], int target[10][10]){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            target[i][j] = origin[i][j];
        }
    }
}
void dfs(){
    int copied[10][10];
    copy(board, copied); //배열 복사 해두기
    for(auto viruse: virused){
        queue<pair<int, int>> Q;
        Q.push(viruse);
        while(!Q.empty()){
            int y = Q.front().first;
            int x = Q.front().second;
            for(int j=0; j<4; j++){
                int cY = y + dY[j];
                int cX = x + dX[j];
                if(0 <= cY && cY < N && 0<= cX && cX <M){
                    if(board[cY][cX] == 0){
                        board[cY][cX] = 2;
                        Q.push({cY,cX});
                    }
                }
            }
            Q.pop();
        }
    }
    int safezone = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(board[i][j] == 0) safezone++;
        }
    }
    mx = max(mx, safezone);
    copy(copied, board); //배열 돌려놓기
}

void bfs(int y, int cnt){
    if (cnt == 3){
        dfs(); //벽 세개가 배치되었다면 계산
        return;
    }
    else{
        // 모든 경우의 수의 벽 배치
        for(int i = y; i<N; i++){
            for(int j=0; j<M; j++){
                if(board[i][j] == 0){
                    board[i][j] = 1;
                    bfs(y, cnt+1);
                    board[i][j] = 0;
                }
            }
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
            if(board[i][j] == 2) {
                virused.push_back({i, j});
            }
        }
    }

    bfs(0, 0);
    
    cout<<mx;

}

