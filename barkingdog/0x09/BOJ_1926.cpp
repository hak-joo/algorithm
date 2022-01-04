#include <utility>
#include <iostream>
#include <queue>
using namespace std;

int board[500][500];
bool vis[500][500];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void){
    int m, n;
    std::cin >> n>> m;
    for(int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            std::cin >> board[i][j];
        }
    }

    int pictureNum = 0;
    int maxArea = 0;

    for(int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if(board[i][j] == 0 || vis[i][j]) continue;
            pictureNum ++;
            queue<pair<int,int>> Q;
            vis[i][j] = 1;
            Q.push({i,j});
            int area = 0;
            while(!Q.empty()){
                area++;
                pair<int, int> cur = Q.front(); Q.pop();
                for (int i=0; i<4; i++){
                    int nx = cur.first + dx[i];
                    int ny = cur.second + dy[i];
                    if (nx<0 || nx >=n || ny<0 || ny>=m) continue;
                    if (vis[nx][ny] || board[nx][ny] != 1) continue;
                    vis[nx][ny] = 1;
                    Q.push({nx,ny});
                }
            }
            maxArea = max(maxArea, area);
        }
    }
    cout<<pictureNum<<"\n" << maxArea;
}