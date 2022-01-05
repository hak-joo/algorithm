#include <iostream>
#include <queue>
#include <utility>

using namespace std;


int board[102][102];
bool vis[102][102];
int chk[102][102];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


int main(void){
    int m, n;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
        }
    }
    int count = 0;
    queue<pair<int,int>> Q;
    Q.push({0,0});
    vis[0][0] = true;
    chk[0][0] = 1;
    bool arive = false;
    while(!Q.empty()){
        pair<int, int> cur = Q.front(); Q.pop();
        if(cur.first == n && cur.second == m) break;
        for(int i=0; i<4; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx<0 || ny<0) continue;
            if (vis[nx][ny] || board[nx][ny] != 1) continue; // 방문한 곳  제외
            vis[nx][ny] = 1;
            Q.push({nx,ny});
            if(chk[nx][ny] == 0){
                chk[nx][ny] = chk[cur.first][cur.second] + 1;
            }
        }
    }

    cout<< chk[n-1][m-1];


}