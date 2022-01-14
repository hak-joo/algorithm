#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int board[25][25];
int tilted[25][25];
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
void rotate(){
    int tmp[25][25];
    for(int i=0; i<n; i++){
        for(int j =0; j<n; j++){
            tmp[i][j] = board[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            board[i][j] = tmp[n-1-j][i];
        }
    }
}
void setValue(int dir){

    while(dir--){
        rotate();
    }
    
    for(int i=0; i<n; i++){
        int cur_idx = 0;
        for(int j=0; j<n; j++){
            if(board[i][j] == 0) continue;
            if (cur_idx == 0)
                board[i][cur_idx++] = board[i][j];

            else if(board[i][cur_idx-1] == board[i][j]) 
                board[i][cur_idx-1] = board[i][j]*2;
            else 
                board[i][cur_idx++] = board[i][j];
        }

        for(int j = cur_idx; j<n; j++){
            board[i][j] = 0;
        }   
    }       
}

void arrayMax(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            mx = max(mx, board[i][j]);
        }
    }
}

void func(int cnt){
    if (cnt == 5){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<< board[i][j] << " ";
            }
            cout<<"\n";
        }
        arrayMax();

        return;
    }
    for(int i=0; i<4; i++){
        copy(temp, board);
        setValue(i);
        func(cnt+1);
        copy(board,temp);
    }
}

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);


    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
        }
    }
    func(0);
    cout<<mx;
}