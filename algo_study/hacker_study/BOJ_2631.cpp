#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;
int N;
vector<int> v;
int DP[205];

int main(void){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> N;
    int input;
    
    for(int i=0; i<N; i++){
        cin >> input;
        v.push_back(input); 
        DP[i] = 1;
    }
    int mn = INT_MAX;
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<i; j++){
            if(v[j] <= v[i])  DP[i] = max(DP[i], DP[j]+1); 
        }
        mn = min(mn, N-DP[i]);
    }
    cout << mn;

}