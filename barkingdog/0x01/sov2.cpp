//주어진 길이 N의 int 배열 arr에서 합이 100인 서로 다른 위치의 두 원소가 존재하면 1,
//존재하지 않으면 0을 반환하는 함수 func2(int arr[], int N) 작성.
//arr의 각 수는 0이상 100이하. N은 1000이하

#include <iostream>
using namespace std;
int func2(int arr[], int N);

int main(void){
    int arr[2] = {50,42};
    cout<< func2(arr, sizeof(arr));

}

int func2(int arr[], int N){
    for (int i=0; i<N-1; i++){
        for(int j=i+1; j<N; j++){
            if (arr[i] + arr[j] == 100) return 1;
        }
    }
    return 0;
}