#include <iostream>
#include <algorithm>

using namespace std;
int N;
int arr[60];
int mx = -1;

int main(void){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i];

    for(int i=0; i<N; i++) {
        int idx = i;
        int left = 0;
        int right = 0;
        double cur, inc;
        if(i !=0){
            idx--, left++; //바로 왼쪽은 보이므로
            inc = (double)(arr[i] - arr[idx]) / (i-idx);
            cur = inc;
            while(1){
                --idx;
                if(idx < 0) break;
                inc = (double)(arr[i] - arr[idx]) / (i-idx);
                if(cur > inc){
                    left++;    
                    cur = inc;
                }
            }           
        }
        //right
        idx = i;
        if(i != N-1){
            idx++, right++;
            inc = (double)(arr[idx] - arr[i]) / (idx-i);
            cur = inc;
            while(++idx){
                if(idx == N) break;
                inc = (double)(arr[idx] - arr[i]) / (idx-i);
                if(cur < inc){
                    right++;
                    cur = inc;
                }              
            }                     
        }
        mx = max(mx, left+right);
    }
    cout << mx;

}