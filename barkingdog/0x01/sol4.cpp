//N이하의 수 중에서 가장 큰 2의 거듭제곱수를 반환하는 함수 func4(int N)을 작성하라
//N은 10억 이하의 자연수

#include <iostream>
using namespace std;

int func4(int N);

int main(void){
    cout <<func4(97615282);
}

int func4(int N){
    int max =1;
    while(2*max <= N) max *=2;
    return max;
}