#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void queen(int k);
bool checkArray(int row, int col);

vector<pair<int, int>> queenExist;

int n;
int cnt = 0;

int main(void)
{
    cin >> n;
    queen(0);
    cout<<cnt;
}

void queen(int k){
    if (k == n){
        cnt++;
        return;
    }
    for(int i=0; i<n; i++){ //행에 대해서
        if(checkArray(k, i)){ //가능하다면
            queenExist.push_back({k,i});
            queen(k+1);
            queenExist.pop_back();
        }    
    }
}

bool checkArray(int row, int col){
   for(auto p : queenExist){
       int i = p.first;
       int j = p.second;

       if(row == i || col == j || fabs(row - i) == fabs(col - j)){
           return false;
       }
   }
   return true;
}