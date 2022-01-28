#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,k;
pair<int,int> item[100005];
int DP[105][100005];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    for(int i=1; i<=n; i++)
        cin >> item[i].first >> item[i].second;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            DP[i][j] = DP[i-1][j];
            if(item[i].first <=j)
                DP[i][j] = max(item[i].second + DP[i-1][j-item[i].first], DP[i][j]);
        }

    }
    cout << DP[n][k];
}