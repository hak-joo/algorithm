//N이 제곱수이면 1을 반환하고 제곱수가 아니면 0을 반환하는 함수 func3(int N)을 작성하라. N은 10억 이하의 자연수이다.

#include <iostream>
using namespace std;

int func3(int N);

int main(void){
    cout <<func3(757580036);
}

int func3(int N){
    for (int i=0; i< N; i++){
        if (i*i == N) return 1;
    }
    return 0;
}

