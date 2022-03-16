#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int subin, sister;
int cnt = 0;
bool isVisited[100005] = {false};

void find(int location){
    if(location == sister) return;

    queue<int> q;
    q.push(location);
    isVisited[location] = true;

    while(!q.empty()){
        int size = q.size();
        for(int i=0; i<size; i++){
            int frt = q.front();
        
            if(frt == sister) return;

            if(frt-1 >=0 && !isVisited[frt-1]) {
                q.push(frt-1);
                isVisited[frt-1] = true;
            }
            if(frt+1 <=100000 && !isVisited[frt+1]) {
                q.push(frt+1);
                isVisited[frt+1] = true;
            }
            if(frt*2 <= 100000 && !isVisited[frt*2]){
                q.push(frt*2);
                isVisited[frt*2] = true;
            }

            q.pop();
        }
        cnt++;        
    }

}

int main(void){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> subin >> sister;
    find(subin);
    cout<<cnt;
}