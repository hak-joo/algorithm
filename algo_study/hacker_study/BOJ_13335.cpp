#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<pair<int, int>> onBridge; //first: 무게, second: 도착까지 남은 시간
queue<int> truckQ;

int currentWeight;

int result;
int n, w, L;
int truck;

int main(void){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> w >> L;
    
    for(int i=0; i<n; i++){
        cin >> truck;
        truckQ.push(truck);        
    }
    while(1){       
        if(onBridge.size() ==0 && truckQ.empty()) break;
        if(onBridge.size() !=0 ){
            if(onBridge.front().second == 0) { //가장 앞이 도착
                currentWeight -= onBridge.front().first; //무게 빼주기
                onBridge.erase(onBridge.begin());                
            }
        }
        if(!truckQ.empty()){
            if(L - currentWeight - truckQ.front() >=0){ //들어갈 수 있는가
                onBridge.push_back({truckQ.front(), w});
                currentWeight += truckQ.front();
                truckQ.pop();
            }
        }
        
        for(int i=0; i<onBridge.size(); i++){
            onBridge[i].second = onBridge[i].second - 1;
        }
        result++;
    }

    cout<<result;
}