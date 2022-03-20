#include <iostream>

using namespace std;

int board[505][505] = {0};
int H, W;
int res = 0;
int main(void){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    cin >> H >> W;
    int height;
    for(int i=0; i<W; i++){
        cin >> height;
        for(int j=0; j<height; j++) board[j][i] = 1;
    }
    for(int i=0; i<H; i++){
        bool chk = false;
        int cnt = 0;
        for(int j=0; j<W; j++){
            if(board[i][j] == 1 && chk){
                res+=cnt;
                cnt = 0;
            } else if (board[i][j] == 1 && !chk) {
                chk = true;
                cnt = 0;
            }
            else if(board[i][j] == 0) cnt++;
        }
    }
    cout << res;

}