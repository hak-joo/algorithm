#include <iostream>
#include <algorithm>

using namespace std;

int RGB[1001][3];
int DP[1001][3];
int n;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for(int i=1; i<=n; i++){
        for(int j=0; j<3; j++) cin>>RGB[i][j];
    }
        

    DP[1][0] = RGB[1][0];
    DP[1][1] = RGB[1][1];
    DP[1][2] = RGB[1][2];

    for(int i=2; i<=n; i++){
        DP[i][0] = min(DP[i-1][1], DP[i-1][2]) + RGB[i][0];
        DP[i][1] = min(DP[i-1][0], DP[i-1][2]) + RGB[i][1];
        DP[i][2] = min(DP[i-1][0], DP[i-1][1]) + RGB[i][2];
    }
    int mn = min(DP[n][0], DP[n][1]);
    cout << min(mn, DP[n][2]);
    
}