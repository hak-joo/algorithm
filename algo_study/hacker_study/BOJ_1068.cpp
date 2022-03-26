#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> par[55];
int N;
int deleteIdx;
int cnt = 0;
void func(int idx){
    if(idx == deleteIdx) return;
    if(par[idx].empty()){ //leaf
        cnt++;
        return;
    }
    for(auto ch: par[idx]){
        if(par[idx].size() == 1 && ch == deleteIdx) cnt++; //잘린 곳을 가리킬 때 (leaf)
        else{
            func(ch);
        }
    }
}

int main(void){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;

    int input;
    int root;
    for(int i=0; i<N; i++){
        cin >> input;
        if(input == -1) root = i;
        else par[input].push_back(i); //부모 등록
    }
    cin >> deleteIdx;
    func(root);

    cout<< cnt;
    
    

}
