#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <unistd.h>

using namespace std;

vector<pair<int, int>> Queen;

int N;
int res = 0;

bool chk(int y, int x){
    for(auto q: Queen){
        int qY = q.first;
        int qX = q.second;    
        if(qY == y || qX == x || abs(qY-y) == abs(qX-x)) return false;
    }
    return true;
}

void queen(int k){
    
    if(k == N){
        res++;
        return;
    }
    for(int x = 0; x<N; x++){
        if(chk(k,x)){
            Queen.push_back({k,x});
            queen(k+1);
            Queen.pop_back();
        }
    }

}

int main(void){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    queen(0);
    cout<< res;
}