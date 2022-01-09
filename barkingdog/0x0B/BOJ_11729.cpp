#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int,int>> ans; //이동한 로그 저장
int sum = 0; // 움직인 횟수

void Hanoi(int s, int e, int N){
    if(N == 0) return;
    Hanoi(s, 6-s-e, N-1); // s 지점에서 6-s-e지점까지 N-1개를 옮긴다.

    sum++;
    ans.push_back({s, e}); // 가장 큰 값을 맨 끝으로 옮기는 작업

    Hanoi(6-s-e, e, N-1);
    return;
}

int main(void){
    int num;
    cin >> num;

    Hanoi(1, 3, num);
    cout<<sum<<"\n";
    for(auto v: ans){
        cout<< v.first<< " "<< v.second << "\n";
    }
}