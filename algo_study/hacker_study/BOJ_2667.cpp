#include <iostream>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int board[1001][1001] = {0};
bool isVisited[1001][1001] = {false};
int cnt = 0;
vector<int> res;
int N;

void func(int y, int x, int group_num){
    queue<pair<int,int>> q;
    q.push({y,x});
    while(!q.empty()){
        int x, y;
        y = q.front().first;
        x = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(board[ny][nx] == 1 && !isVisited[ny][nx]){
                q.push({ny, nx});
                group_num++;
                isVisited[ny][nx] = true;
            }
        }
    }
    res.push_back(group_num);
}

int main(void){

    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    string input;
    for(int y=0; y<N; y++){
        cin>>input;
        for(int x=0; x<N; x++){
            int num = input[x] - '0';
            board[y][x] = num;
        }
    }
    for(int y=0; y<N; y++){
        for(int x=0; x<N; x++){
            if(board[y][x] == 1 && !isVisited[y][x]){
                cnt++;
                isVisited[y][x] = true;
                func(y,x,1);
            }
        }
    }
    cout<<cnt<<"\n";
    sort(res.begin(), res.end());
    for(auto i: res) cout<<i<<"\n";

}