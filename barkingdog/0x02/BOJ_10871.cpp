#include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,X;
    cin >> N;
    cin >> X;
    int *arr = new int[N];

    for (int i=0; i<N; i++) cin >> arr[i];
    for (int i=0; i<N; i++){
        if(X>arr[i]) cout<<arr[i]<<" ";
    }
    delete[] arr;
}