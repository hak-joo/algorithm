#include <iostream>
#include <queue>

using namespace std;

int F,S,G,U,D;
bool isVisited[1000005] = {0};
bool found = false;
int cnt = 0;

void bfs(){
    queue<int> q;
    q.push(S);
    cnt = -1;
    while(!q.empty()){
        int size = q.size();
        ++cnt;
        for(int i=0; i<size; i++){
            int cur = q.front();
            q.pop();
            if(cur == G) {
                found = true;
                break;
            }
            if(cur+U <= F){
                if(!isVisited[cur+U]) {
                    q.push(cur + U);
                    isVisited[cur+U] = true;
                }
            }
            if (cur-D > 0){
                if(!isVisited[cur-D]) {
                    q.push(cur-D);
                    isVisited[cur-D] = true;
                }
            }
        }
        if (found) break;
    }   
}

int main(void){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> F >> S>> G>> U>> D;
    isVisited[S] = true;
    bfs();
    if(found) cout << cnt;
    else cout << "use the stairs";
}