#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second



int board[502][502] = {};
bool vis[502][502];
int n= 7, m =10;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

// 보드에서 같은 색으로 연결된 요소들을 찾기
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int, int>> Q;
    vis[0][0] = 1;
    Q.push({0,0});

    while(!Q.empty()){
        pair<int,int> cur = Q.front(); Q.pop();
        cout<<"("<<cur.X << ", "<<cur.Y <<") -> ";
        for (int dir = 0; dir <4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >=n || ny < 0 || ny >= m) continue;
            if(vis[nx][ny] || board[nx][ny] != 1) continue;
            vis[nx][ny] = 1;
            Q.push({nx,ny});
        }
    }    
}