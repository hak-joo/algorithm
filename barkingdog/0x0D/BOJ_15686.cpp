#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int mn =0x7f7f7f7f;
int N, M;
int arr[55][55];
vector<pair<int,int>> chicken;
vector<pair<int, int>> house;

int main(void){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 2) chicken.push_back({i, j});
            if(arr[i][j] == 1) house.push_back({i,j});
        }
    }

    vector<int> brute(chicken.size(), 1); // 1로 채워둠
    fill(brute.begin(), brute.begin() + chicken.size() -M, 0); // 처음부터 size-m개까지는 0으로 채운다
    // 결국 이 시점에서 n 개중 m개를 선택하는 조합을 만들 수 있음

    do{
        int dist = 0;
        for(auto h: house){ // 모든 집에 대해
            int tmp = 0x7f7f7f7f;
            for (int i=0; i< chicken.size(); i++){ // M개의 치킨집을 하나씩 돌며 체크
                if(brute[i] == 0) continue;
                tmp = min(tmp, abs(chicken[i].first - h.first) + abs(chicken[i].second - h.second));
            }
            dist += tmp; //한 집에 대한 치킨집의 최소 거리
        }
        mn = min(dist, mn);
    } while(next_permutation(brute.begin(), brute.end()));

    cout<<mn;

}