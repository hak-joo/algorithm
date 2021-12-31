#include <iostream>

using namespace std;

int func1(int arr[], int N);
int main(void){
    int arr[3] = {27, 72, 1};
    cout<< func1(arr, 3);
}

int func1(int arr[], int N){
    int occur[101] = {};
    for(int i=0; i<N; i++){
        if(occur[100-arr[i]] == 1) return 1;
        else occur[arr[i]]++;
    }
    return 0;
}