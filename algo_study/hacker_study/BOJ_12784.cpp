#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;

vector<pair<int, int>> V[1005];

int T;

int N, M, W;

int dfs(int prev, int cur, int weight){
    int sum = 0;
    for(auto item: V[cur]){
        if(prev != item.first) sum+= dfs(cur, item.first, item.second); //부모노드가 아니라 밑으로 내려가는 경우
    }
    if(sum == 0) return weight; //리프 노드일 때
    else return min(sum, weight);
}

int main(void){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);

    cin >> T;
    while(T--){
        cin >> N >> M;
        
        int res = 0;

        int start, end, dynamite;
        while(M--){
            cin >> start >> end >> dynamite;
            V[start].push_back({end, dynamite});
            V[end].push_back({start, dynamite});
        }
        res = dfs(0, 1, INT_MAX);

        if(M==0 || res == INT_MAX) cout<<"0\n";
        else cout << res << "\n";

        for(int i=0; i<=N; i++) V[i].clear();
    }


}