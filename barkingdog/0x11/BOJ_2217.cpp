#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int rope[100005];
int cnt = 0;
int weight = 0;

int main(void){
    cin >> n;
    for(int i=0; i<n; i++)
       cin >> rope[i];
    sort(rope, rope+ n, greater<>());

    for(int i=0; i<n; i++){
        if(i == 0){
            cnt++;
            weight += rope[i];
        } else{
            if(weight < weight + (rope[i]/ (cnt + 1))){
                weight += (rope[i]/ (cnt + 1));
                cnt++;
            } else {
                break;
            }
        }
    }
    cout<< weight;
        
}