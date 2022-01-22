#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
int D[1000001];
int lg[1000001];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    D[1] = 0;

    for(int i=2; i<=n; i++){
        D[i] = D[i-1] + 1;
        lg[i] = 1;
        if(i % 2 == 0) {
            D[i] = min(D[i], D[i/2] + 1);
            if (D[i] == D[i/2] + 1) lg[i] = 2;
        }
        if(i % 3 == 0) {
            D[i] = min(D[i], D[i/3] + 1);
            if(D[i] == D[i/3] + 1) lg[i] = 3;
        }
    }
    int result = D[n];
    cout<< result << "\n";
    while(n){
        cout<< n<< " ";
        if (lg[n] == 1) n-=1;
        else if (lg[n] == 2) n/= 2;
        else if (lg[n] == 3) n/= 3;
        else n-=1 ; 
    }
}