#include <iostream>
#include <vector>
using namespace std;

int N, gen, dir;
bool isVisited[105][105] = {false};
vector<int> v;
int cur_x, cur_y;

void mark(int n){
    if(n==0) isVisited[++cur_x][cur_y] = true;
    else if (n==1) isVisited[cur_x][--cur_y] = true;
    else if (n==2) isVisited[--cur_x][cur_y] = true;
    else if(n==3) isVisited[cur_x][++cur_y] = true;
}

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    while(N--){
        v.clear();
        cin >> cur_x >> cur_y >> dir >> gen;
        isVisited[cur_x][cur_y] = 1;
        v.push_back((dir)%4);
        while(gen--){
            for(int i=v.size()-1; i>=0; i--)
                v.push_back((v[i]+1)%4);
        }

        for(int i=0; i<v.size(); i++) mark(v[i]);
    }
    int result = 0;
    for(int i=0; i<101; i++){
        for(int j=0; j<101; j++){
            if(isVisited[i][j] && isVisited[i+1][j] && isVisited[i][j+1] && isVisited[i+1][j+1]) 
                result++;
        }
    }
    cout<< result;
}

//   1
// 2   0
//   3
/* 
0세대: 0
1세대: 0 1
2세대: 0 1 2 1
3세대: 0 1 2 1 2 3 2 1
4세대: 0 1 2 1 2 3 2 1 2 3 0 3 2 3 2 1 
*/