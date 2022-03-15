#include <iostream>
#include <vector>
#include <cmath>
#include <map>

#include <algorithm>

using namespace std;

int N, Q, c, v;
map<int, int> treasure;
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> Q;
    int value;
    int uCnt, dCnt;

    for(int i=0; i<N-1; i++) cin >> value;
    while(Q--){
        cin >> c >> v;
        if(c == 1) treasure.insert({v,v});
        
        else if (c == 2){
            if(treasure.size()==0) cout<<"-1\n";
            else{
                if(treasure.count(v) == 1) cout<<"0\n"; //움직일 필요 없음
                else {
                    treasure.insert({v,v});
                    auto iter = treasure.find(v);
                    auto endIter = treasure.end();
                    endIter--;

                    if (treasure.begin() == iter){
                        iter++;
                        cout << iter->first - treasure[v] << "\n";
                    } else if (iter == endIter){
                        endIter--;
                        cout << treasure[v] - endIter->first<<"\n";
                    }
                    else {       
                        int n1, n2;
                        iter--;
                        n1 = treasure[v] - iter->first;
                        iter++; iter++;
                        n2 = iter->first - treasure[v];

                        if(n1 < n2) cout << n1 << "\n";
                        else cout << n2 <<"\n"; 
                    }
                    treasure.erase(v);
                }
            }
        }
    }


}
