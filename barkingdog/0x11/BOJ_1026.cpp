#include <iostream>
#include <algorithm>

using namespace std;


int n;
int A[55];
int B[55];
int selected[55];

int result[55];

int main(void){
    
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> A[i];
    for(int i=0; i<n; i++)
        cin >> B[i];
    fill(selected, selected+n, 0);
    sort(A, A+n);

    for(int i=0; i<n; i++){
        int max = -1;
        int cur;
        for(int idx = 0; idx < n; idx++){ //잔여 중 최대값 찾기
            if(selected[idx] == 0 && max < B[idx]){
                cur = idx;
                max = B[idx];
            }
        }
        result[cur] = A[i];
        selected[cur] = 1;
        max = -1;
    }
    int sum =0;
    for(int i=0; i<n; i++){
        sum += result[i] * B[i];
    }
    cout<<sum;




}