#include <iostream>

using namespace std;

int board[11][11] = {0,};
int score = 0;

void chkBlueSpecial(){
    if(board[0][4] + board[1][4] + board[2][4] + board[3][4] > 0){ //4번째에 있다는 것은 5번째에도 있다는 것임. 그러므로 2번 밀어준다.
        for(int x=9; x>3; x--){
            for(int y=0; y<4; y++){
                board[y][x] = board[y][x-2];
            }
        }

        return;
    }
    if (board[0][5] + board[1][5] + board[2][5] + board[3][5] > 0){ //1번 밀기
        for(int x=9; x>3; x--){
            for(int y=0; y<4; y++){
                board[y][x] = board[y][x-1];
            }
        }
        return;
    }
    return;
}

void chkBlue(int x){

    if(x==4 || x==5){
        chkBlueSpecial();
    }
    else{
        for(int l=0; l<2; l++){//한 줄이 없어지면 최대 1번 더 지울 수 있는 기회가 생긴다.
            if(board[0][x] + board[1][x] + board[2][x] + board[3][x] == 4){
                score++;
                for(int i=0; i<4; i++) board[i][x] = 0;
            
                for(int dx=x; dx>3; dx--){
                    for(int dy=0; dy<4; dy++){
                        board[dy][dx] = board[dy][dx-1];
                    }
                }
            }
        }
        
    }

    
}

void blue(int t, int y){
    int i;
    if(t==1){ // 하나
        for(i=3; i<10; i++){    
            if(board[y][i+1] == 1){
                board[y][i] = 1;
                chkBlue(i);
                break;
            }
        }      
    } else if (t==2){ //세로로 두 개
        for(i=3; i<10; i++){
            if(board[y][i+1] == 1 || board[y+1][i+1] == 1) {
                board[y][i] = 1;
                board[y+1][i] = 1;
                chkBlue(i);
                break;
            }
        }      

    } else if (t==3){ // 가로로 두 개
        for(i=3; i<9; i++){
            if(board[y][i+2] == 1) {
                board[y][i] = 1;
                board[y][i+1] = 1;
                chkBlue(i+1);
                chkBlue(i);
                break;
            }
        }
    }
}

void chkGreenSpecial(){
    if(board[4][0] + board[4][1] + board[4][2] + board[4][3] > 0){ //2번 밀기
        for(int y=9; y>3; y--){
            for(int x=0; x<4; x++){
                board[y][x] = board[y-2][x];
            }
        }

        return;
    }
    if (board[5][0] + board[5][1] + board[5][2] + board[5][3] > 0){ //1번 밀기
        for(int y=9; y>3; y--){
            for(int x=0; x<4; x++){
                board[y][x] = board[y-1][x];
            }
        }
        return;
    }
    return;
}

void chkGreen(int y){
    if(y == 4 || y == 5){
        chkGreenSpecial();
    }else{
        for(int l=0; l<2; l++){ //한 줄이 없어지면 최대 1번 더 지울 수 있는 기회가 생긴다.
            if(board[y][0]+board[y][1]+board[y][2]+board[y][3] == 4){
                score++;
                for(int i=0; i<4; i++) board[y][i] = 0;
            
                for(int dy=y; dy>3; dy--){
                    for(int dx=0; dx<4; dx++){
                        board[dy][dx] = board[dy-1][dx];
                    }
                }
            }
        }
        
    }
}

void green(int t, int x){
    int i;
    if(t==1){
        for(i=3; i<10; i++){
            if(board[i+1][x] == 1) {
                board[i][x] = 1;
                chkGreen(i);
                break;
            }
        }
 
    } else if (t==2){
        for(i =3; i<9; i++){
            if(board[i+2][x] == 1) {
                board[i][x] = 1;
                board[i+1][x] = 1;
                chkGreen(i+1);
                chkGreen(i);
                break;
            }
        }
        
    } else if (t==3){
        for(i=3; i<10; i++){
            if(board[i+1][x] == 1 || board[i+1][x+1] == 1) {
                board[i][x] = 1;
                board[i][x+1] = 1;
                chkGreen(i);
                break;
            }
        }        
    }
}

int calRemain(){
    int cnt = 0;
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if(board[i][j] == 1) cnt++;
        }
    }
    return cnt;
}


int main(void){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int x, y, t, N;
    cin >> N;
    for(int i=0; i<4; i++){
        board[i][10] = 1;
        board[10][i] = 1;
    }
    while(N--){
        cin >> t >> x >> y;
        blue(t, y);
        green(t, x);
    }
    

    cout << score <<"\n";
    cout << calRemain();
}