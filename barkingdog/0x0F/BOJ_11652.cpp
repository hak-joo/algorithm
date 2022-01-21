#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int cnt = 0;
long int mxvl = -1 * (2e+62+1);
int mxcnt = 0;
int n;
int arr[100001];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    sort(arr, arr+n);

    for(int i=0; i<n; i++){
        if(i == 0){
            cnt++;
            mxvl = arr[i];
            continue;
        }
        if (arr[i] == arr[i-1]){ //같을 때 카운트 증가
            cnt++;
        }
        else {
            if(cnt > mxcnt) {
                mxcnt = cnt;
                cnt = 0;
                mxvl = arr[i-1];
            } else{
                cnt = 0;
            }
        }
    }
    if (cnt > mxcnt){
        mxcnt = cnt;
        mxvl = arr[n-1];
    }
    cout << mxvl;

}