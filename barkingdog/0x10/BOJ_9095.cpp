#include <iostream>
#include <algorithm>

using namespace std;

int n;
int t;
int D[1000001];
int nArr[11];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    D[1] = 1, D[2] = 2, D[3] = 4;
    for(int i=4; i<11; i++) D[i] = D[i-3] + D[i-2] + D[i-1];
    cin >> n;
    while(n--){
        cin >> t;
        cout<< D[t] << "\n";
    }
}