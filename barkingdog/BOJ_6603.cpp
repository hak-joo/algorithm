#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
vector<int> v;
int res[6];

void dfs(int idx, int cnt){
    if(cnt == 6){
        for(int i=0; i<6; i++) cout<< res[i] << " ";
        cout<<"\n";
        return;
    } else{
        for(int i= idx; i<v.size(); i++){
            res[cnt] = v[i];
            dfs(i+1, cnt+1);
        }
    }
}

int main(void){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    while(1){
        cin >> N;
        if(N ==0) break;
        while(N--){
            int input;
            cin >> input;
            v.push_back(input);
        }
        dfs(0,0);
        cout<<"\n";
        v.clear();
    }
    

}