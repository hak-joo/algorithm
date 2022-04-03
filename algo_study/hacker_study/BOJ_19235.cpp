#include <iostream>
#include <queue>

using namespace std;

int board[11][11] = {0,};
int score = 0;


void moveBlue(int x){
    for(int i=0; i<4; i++){
        int blockNum = 0;
        for(int j=4; j<x; j++){
            if(board[i][j] == 1) blockNum++;
        }
        int dir;
        for(dir=x; dir<10; dir++){
            if(board[i][dir] == 1) break;
        }
        for(int j=dir-1; j>3; j--){
            if(blockNum >0) {
                board[i][j] = 1;
                blockNum--;
            } else board[i][j] = 0;
        }
    }
}
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


bool chkBlue(){
    vector<int> v;
    int location =100;
    for(int x=6; x<10; x++){
        int sum = 0;
        for(int y=0; y<4; y++){
            sum += board[y][x];
        }
        if(sum == 4) {
            v.push_back(x);
            location = min(x,location);
        }
    }
    score += v.size();

    for(auto x: v){
        for(int y=0; y<4; y++){
            board[y][x] = 0;
        }
    }
    if(location != 100) {
        moveBlue(location);
        return true;
    }
    return false;
}

void blue(int t, int y){
    int i;
    if(t==1){ // 하나
        for(i=3; i<10; i++){    
            if(board[y][i+1] == 1){
                board[y][i] = 1;
                break;
            }
        }      
    } else if (t==2){ //세로로 두 개
        for(i=3; i<10; i++){
            if(board[y][i+1] == 1 || board[y+1][i+1] == 1) {
                board[y][i] = 1;
                board[y+1][i] = 1;
                break;
            }
        }      

    } else if (t==3){ // 가로로 두 개
        for(i=3; i<9; i++){
            if(board[y][i+2] == 1) {
                board[y][i] = 1;
                board[y][i+1] = 1;
                break;
            }
        }
    }
    while(chkBlue());
    chkBlueSpecial();
}

void moveGreen(int y){
    for(int i=0; i<4; i++){
        int blockNum = 0;
        for(int j=4; j<y; j++){
            if(board[j][i] == 1) blockNum++;
        }
        int dir;
        for(dir=y; dir<10; dir++){
            if(board[dir][i] == 1) break;
        }
        for(int j=dir-1; j>3; j--){
            if(blockNum > 0){
                board[j][i] = 1;
                blockNum--;
            } else board[j][i] = 0;
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

bool chkGreen(){
    vector<int> v;
    int location = 100;
    for(int y=6; y<10; y++){
        int sum = 0;
        for(int x=0; x<4; x++){
            sum += board[y][x];
        }
        if(sum == 4){
            v.push_back(y);
            location = min(y,location);
        }
    }
    score += v.size();

    for(auto y: v){
        for(int x =0; x<4; x++){
            board[y][x] = 0;
        }
    }
    if(location != 100){
        moveGreen(location);
        return true;
    }
    return false;
}

void green(int t, int x){
    int i;
    if(t==1){
        for(i=3; i<10; i++){
            if(board[i+1][x] == 1) {
                board[i][x] = 1;
                break;
            }
        }
 
    } else if (t==2){
        for(i =3; i<9; i++){
            if(board[i+2][x] == 1) {
                board[i][x] = 1;
                board[i+1][x] = 1;
                break;
            }
        }
        
    } else if (t==3){
        for(i=3; i<10; i++){
            if(board[i+1][x] == 1 || board[i+1][x+1] == 1) {
                board[i][x] = 1;
                board[i][x+1] = 1;
                break;
            }
        }        
    }
    while(chkGreen());
    chkGreenSpecial();
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