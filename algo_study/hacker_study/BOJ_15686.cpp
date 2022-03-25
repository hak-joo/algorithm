#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<pair<int,int>> chicken;
vector<pair<int,int>> home;
vector<int> tmp;
vector<pair<int,int>> target;

int N, M;

int main(void){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> M;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int input;
            cin >> input;
            if(input == 1) home.push_back({i,j});

            else if (input == 2) chicken.push_back({i, j});
                
        }
    }

    //치킨 개수 중, m 개를 뽑아야 함.
    //뽑아야 하는 수만큼 0 푸쉬, 나머지 1 푸쉬
    for(int i=0; i<M; i++) tmp.push_back(0);
    for(int i=0; i<chicken.size() - M; i++) tmp.push_back(1);
    
    int res = 2147483646;
    do{
        target.clear(); //target : 폐업하지 않을 치킨집의 모임.
        int totalDis = 0; //totalDis: 폐업하지 않을 치킨집들중 거리 계산 후 모든 집에서 치킨집까지의 거리
        for(int i=0; i<tmp.size(); i++){
            if(tmp[i] == 0) {
                target.push_back({chicken[i].first, chicken[i].second});
            }
        }
        for(auto h: home){
            int dis = 2147483646;
            for(auto t: target){ //집에서 가장 가까운 치킨집 거리
                int temp = abs(h.first-t.first) + abs(h.second - t.second);
                dis = min(dis, temp); 
            }
            totalDis += dis; //각 집마다 가장 가까운 치킨집 거리를 더해줌
        }
        res = min(res, totalDis);
    } while(next_permutation(tmp.begin(), tmp.end()));

    cout << res;
}