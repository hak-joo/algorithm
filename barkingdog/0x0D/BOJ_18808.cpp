#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int board[25][25];
int temp[25][25];
int n;
int mx=0;

void copy(int copied[25][25], int origin[25][25]){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            copied[i][j] = origin[i][j];
        }
    }
}

void func(int cnt){
    setValue(0);
}

void setValue(int dir){
    if(dir ==0){ //왼쪽으로 밀기
        int cur_idx = 0; // 넣었던 값의 인덱스
        int cur_vle = -1; //현재 가지고 있는 값
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 0) continue;
                if(cur_vle == -1){
                    cur_vle = board[i][j];
                    continue;
                } 
                if(cur_vle == board[i][j]){
                    board[i][cur_idx++] =  cur_vle;
                    cur_vle = -1;

                } else {
                    board[i][cur_idx++] = cur_vle;
                }
            }   
        }
        
    } else if (dir == 1){ //오른쪽으로 밀기

    } else if (dir == 2){ //위로 밀기

    } else if (dir == 3){ //아래로 밀기

    }
}

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

    fill(board[0], board[50], 0);
    fill(temp[0], board[50], 0);

    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
        }
    }
    func(0);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<< board[i][j]<< " ";
        }
        cout<<"\n";
    }
}