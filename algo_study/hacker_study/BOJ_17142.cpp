#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <memory.h>

using namespace std;


int N, M;
int board[55][55];
int dist[55][55];
bool selected[10];

vector<pair<int,int>> virus;
queue<pair<int, int>> onVirus;

int nonVirus=0;
int dX[4] = {1,0,-1,0};
int dY[4] = {0,1,0,-1};
int res = INT_MAX;

void bfs(){
    int infect = 0, times = 0;
    while(!onVirus.empty()){
        int x = onVirus.front().second;
        int y = onVirus.front().first;
        onVirus.pop();
        for(int i=0; i<4; i++){
            int curX = x + dX[i];
            int curY = y + dY[i];
            if(curX < 0 || curX >= N || curY < 0 || curY >= N) continue;
            if(board[curY][curX] != 1 && dist[curY][curX] == -1){ //방문하지 않았고, 벽이 아닐 때
                dist[curY][curX] = dist[y][x] + 1;
                if(board[curY][curX] == 0){
                    infect++;
                    times = dist[curY][curX];
                }
                onVirus.push({curY, curX});
            }
        }
    }
    if(infect == nonVirus && res > times) res = times;

}

void select(int idx, int cnt){
    if(cnt == M){
        memset(dist, -1, sizeof(dist));
        for(int i=0; i<virus.size(); i++){
            if(selected[i]) {
                onVirus.push({virus[i].first, virus[i].second});
                dist[virus[i].first][virus[i].second] = 0;
            };
        }
        bfs();
        return;
    }

    for(int i=idx; i<virus.size(); i++){
        if(!selected[i]){
            selected[i] = true;
            select(i+1, cnt+1);
            selected[i] = false;
        }
    }
}

int main(void){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> board[i][j];
            if(board[i][j] == 2) virus.push_back({i,j});
            if(board[i][j] == 0) nonVirus++;
        }
    }
    int mn = INT_MAX;
    select(0,0);
    mn = min (res, mn);
    
    if(mn == INT_MAX) cout << "-1";
    else cout << mn;

}