#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int tomato[105][105][105];
int res[105][105][105];
int M, N, H;

int dX[4] = {1, 0, -1, 0};
int dY[4] = {0, 1, 0, -1};
int dZ[2] = {-1,1};
queue<pair<pair<int,int>, int>> ripe;

void print(){
    int ans = -1;
    for(int i=0; i<H; i++){ //[y][x][z]
        for(int j=0; j<N; j++){
            for(int k=0; k<M; k++){
                if(tomato[j][k][i] == 0){
                    cout<<"-1";
                    return;
                } else ans = max(ans, res[j][k][i]);
            }
        }
    }
    cout << ans;
}

void bfs(){
    int day = 0;
    
    while(!ripe.empty()){
        int qSize = ripe.size();
        day++;
        while(qSize--){
            int y = ripe.front().first.first;
            int x = ripe.front().first.second;
            int z = ripe.front().second;
            ripe.pop();
            for(int i=0; i<2; i++){
                int curZ = z + dZ[i];
                
                if(0 <= curZ && curZ < H){
                    if(tomato[y][x][curZ] == 0){
                        tomato[y][x][curZ] = 1;
                        ripe.push({{y,x}, curZ});
                        res[y][x][curZ] = day;
                    }
                }
            }
            for(int j=0; j<4; j++){
                int curX = x + dX[j];
                int curY = y + dY[j];
                if(0<=curX && curX <M && 0<=curY && curY < N){
                    if(tomato[curY][curX][z] == 0){
                        tomato[curY][curX][z] = 1;
                        ripe.push({{curY,curX}, z});
                        res[curY][curX][z] = day;
                    }
                }
            }
        }
    }
    print();

    
}

int main(void){

    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    
    cin >> M >> N >> H;
    for(int i=0; i<H; i++){ //[y][x][z]
        for(int j=0; j<N; j++){
            for(int k=0; k<M; k++){
                cin >> tomato[j][k][i];
                if(tomato[j][k][i] == 1) {
                    ripe.push({{j,k}, i});
                    res[j][k][i] = 0;
                } else{
                    res[j][k][i] = -1;
                }
            }
        }
        ;
    }
    bfs();

}
