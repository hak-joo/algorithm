#include <iostream>
#include <algorithm>

using namespace std;

int D[301][2];
int score[301];
int n;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++) cin >> score[i];
    //0일 경우 이전이 없거나 두 칸 뛰어온 경우
    D[1][0] = score[1];
    D[2][0] = score[2];
    D[2][1] = D[1][0] + score[2];
    D[3][0] = score[1] + score[3];
    D[3][1] = score[2] + score[3];
    for(int i=4; i<=n; i++){
        D[i][0] = max(D[i-2][0], D[i-2][1]) + score[i];
        D[i][1] = D[i-1][0] + score[i];
    } 
    cout<< max(D[n][0], D[n][1]);

}