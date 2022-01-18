#include <iostream>

using namespace std;

int main(void){

    int arr[10] = {3,2,7,116,62,235,1,23,55,77};
    int n = 10;

    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            if(arr[i] < arr[j]){
                swap(arr[i], arr[j]);
            }
        }
    }

    for(int i=0; i<n; i++){
        cout<< arr[i]<< " ";
    }
}