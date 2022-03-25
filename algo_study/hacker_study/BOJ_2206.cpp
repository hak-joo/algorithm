#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <climits>
#include <string>
using namespace std;

int board[1005][1005];
bool isVisited[1005][1005][2] = {false};
int res[1005][1005][2] = {1};

int N, M;
int dX[4] = {1,0,-1,0};
int dY[4] = {0,1,0,-1};


void func(){
    queue<pair< pair<int,int>, int>> Q;
    Q.push({{0,0}, 0});

    while(!Q.empty()){
        int y = Q.front().first.first;
        int x = Q.front().first.second;
        int drilled = Q.front().second;
        Q.pop();
        for(int i=0; i<4; i++){
            int cY = y + dY[i];
            int cX = x + dX[i];
            if(0 <= cY && cY < N && 0<=cX && cX < M){ //범위 체크
                
                if(drilled == 0){ //벽 안뚫었을 때
                    if(board[cY][cX] == 1){ //벽일 때
                        if(!isVisited[cY][cX][1]){ //방문 체크 
                            isVisited[cY][cX][1] = true;
                            res[cY][cX][1] = res[y][x][0] + 1;
                            Q.push({{cY,cX}, 1});
                        }
                    } else { //벽 아닐 때
                        if(!isVisited[cY][cX][0]){ //방문 체크
                            isVisited[cY][cX][0] = true;
                            res[cY][cX][0] = res[y][x][0] + 1;
                            Q.push({{cY,cX}, 0});
                        }
                    }
                }
                else if(drilled == 1){ //벽을 뚫었었을 때
                    if(board[cY][cX] ==0 && !isVisited[cY][cX][1]){ //방문 체크
                        isVisited[cY][cX][1] = true;
                        res[cY][cX][1] = res[y][x][1] + 1;
                        Q.push({{cY,cX}, 1});
                    }
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
        for(int j=0; j<M; j++)
        {
            res[i][j][0] = INT_MAX;
            res[i][j][1] = INT_MAX;
        }
    }
    string input;
    for(int i=0; i<N; i++){
        cin >> input;
        for(int j=0; j<input.size(); j++){
            board[i][j] = input[j] - '0';
        }
    }
    isVisited[0][0][0] = true;
    res[0][0][0] = 1;
    func();

    if(res[N-1][M-1][0] == INT_MAX && res[N-1][M-1][1] == INT_MAX){
        cout << "-1";
    } else{
        cout << min(res[N-1][M-1][0], res[N-1][M-1][1]);
    }


}