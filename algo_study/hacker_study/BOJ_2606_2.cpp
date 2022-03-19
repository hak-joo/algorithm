#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[105];
vector<int> arr[101];
int cnt;

void dfs(int k){
    visited[k] = true;
    cnt++;
    for(int i=0; i<arr[k].size(); i++){
        if(!visited[arr[k][i]]) dfs(arr[k][i]);
    }
}

int main(void){
    int N,M;
    cin >> N >> M;
    for(int i=0; i<M; i++){
        int a,b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    dfs(1);
    cout << cnt-1;
}