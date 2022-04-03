#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
int board[20][20];
int temp[20][20];
int N, M, D;
vector<int> archor;
bool isVisited[20][20];
int dX[3] = {-1, 0, 1};
int dY[3] = {0, -1, 0};

struct node{
    int x, y, dis;
};

void copy(int origin[20][20], int copied[20][20]){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            copied[i][j] = origin[i][j];
        }
    }
}

bool check(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(temp[i][j] == 1) return true;
        }
    }
    return false;
}
void down(){
    for(int i = 0; i < M; i++){
        for(int j = N-1; j >= 0; j--){
            if(!temp[j][i]) continue;
            if(j==N-1) temp[j][i] = 0;
            else{
                temp[j][i] = 0;
                temp[j+1][i] = 1;
            }
        }
    }
}
int bfs(){
    queue<pair<int, int>> killed;
    int killCount = 0;
    for(int i=0; i<M; i++){
        queue<node> q;
        if(archor[i] == 1){ //궁수 선택
            if(temp[N-1][i] == 1){
                killed.push({N-1, i});
                continue;
            }
            node n = {i, N-1, 1};
            q.push(n);
            memset(isVisited, false, sizeof(isVisited));
            isVisited[N-1][i] = true;

            while(!q.empty()){ //공격
                int x = q.front().x;
                int y = q.front().y;
                int dis = q.front().dis;
                q.pop();
                if(dis > D) continue;
                if(temp[y][x] == 1){ //찾으면 break
                    killed.push({y,x});
                    break;
                } else{ //없으면 탐색 시작
                    for(int i=0; i<3; i++){
                        int nx = x + dX[i];
                        int ny = y + dY[i];
                        if(nx<0 || nx >=M || ny < 0 || ny >=N) continue;
                        if(!isVisited[ny][nx]){
                            q.push({nx,ny,dis+1}); //큐 넣어줌
                            isVisited[ny][nx] = true;
                        }   
                    } 
                }
            }
        }
    }
    while(!killed.empty()){
        int y = killed.front().first;
        int x = killed.front().second;
        killed.pop();
        if(temp[y][x] == 1){
            killCount++;
            temp[y][x] = 0;
        }
    }
    return killCount;

}

int main(void){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> N >> M >> D;
    int ans = 0;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> board[i][j];
        }
    }
    for(int i=0; i<M-3; i++) archor.push_back(0);
    for(int i=0; i<3; i++) archor.push_back(1);

    do{
        copy(board, temp); //복사 진행
        int sum = 0;
        while(check()){
            sum+=bfs();
            down();
        }
        ans = max(sum, ans);
    } while(next_permutation(archor.begin(), archor.end()));

    cout << ans;
}