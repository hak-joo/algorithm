#include <iostream>
#include <cmath>

using namespace std;

int r, c;
void func1(int N, int y, int x, int &result){
    
    if (x == c && y == r){
        cout<< result;
        return;
    }
    //현재 찾고 있는 범위에 일치하는가?
    if (r < y + N && r >= y && c < x + N && c >= x) {
        func1(N/2, y, x, result); //1사분면
        func1(N/2, y, x + N/2, result); // 2사분면
        func1(N/2, y + N/2, x, result); // 3사분면
        func1(N/2 , y + N/2, x +N/2, result);
    } else{
        result += N * N;
    }

}

int main(void){
    int N;
    int result = 0;

    cin >> N >> r >> c;
    func1(1<<N, 0, 0, result);

}