#include <iostream>
#include <algorithm>

using namespace std;

int board[25][25];
int N;
int mx = -1;

void copy(int origin[25][25], int copied[25][25]){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            copied[i][j] = origin[i][j];
        }
    }
}

void rotate(){
    int rotated[25][25];
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            rotated[i][j] = board[N-1-j][i];
        }
    }
    copy(rotated, board);
}

void slide(int dir, int cnt){
    if (cnt == 5){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                mx = max(mx, board[i][j]);
            }
        }
        return;
    }
    int temp[25][25];
    copy(board, temp);


    while(dir--) rotate();
    int res[25][25] = {};
    for(int i=0; i<N; i++){
        int idx = 0;
        for(int j=0; j<N; j++){
            if(board[i][j] == 0) continue;

            if(res[i][idx] == 0) res[i][idx] = board[i][j];
            else if(res[i][idx] == board[i][j]) res[i][idx++] *= 2;
            else res[i][++idx] = board[i][j];
        }
    }
    copy(res, board);
    
    for(int i=0; i<4; i++){
        slide(i, cnt+1);
    }
    copy(temp, board);

}

int main(void){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> board[i][j];
        }
    }
    
    for(int i=0; i<4; i++){
        slide(i,0);

    }
    cout << mx;


}



