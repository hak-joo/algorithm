//N 이하의 자연수 중에서 3의 배수이거나 5의 배수인 수를 모두 합한 값 반환하는 함수 func1(int N) 작성.
//N은 10만 이하의 자연수
#include <iostream>

using namespace std;
int func1(int n);

int main(){
    int n;
    cin >>n;
    cout<< func1(n);
}

int func1(int n){
    int res = 0;
    for(int i=0; i<n; i++){
        if (i%3 == 0 || i%5 ==0) res +=i;
    }
    return res;
}
