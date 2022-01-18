#include <iostream>

using namespace std;

int arr1[1000001];
int arr2[1000001];
int res[2000002];
int m,n;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n>> m;

    for(int i=0; i<n; i++) cin>> arr1[i];
    for (int i=0; i<m; i++) cin>> arr2[i];

    int nIdx=0;
    int mIdx = 0;

    for(int i=0; i<n+m; i++){
        if(nIdx == n) res[i] = arr2[mIdx++];
        else if(mIdx ==m) res[i] = arr1[nIdx++]; 
        else if(arr1[nIdx] > arr2[mIdx]) res[i] = arr2[mIdx++];
        else res[i] = arr1[nIdx++];
    }
    for(int i=0; i<n+m; i++) cout<<res[i]<< " ";
}