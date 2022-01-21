#include <iostream>
#include <algorithm>

using namespace std;

int n;
int score = 0;
int arr[301];
int mx = 0;

void game(int floor, int count){
    score += arr[floor];
    int temp;
    if (floor == 0) {
        mx = max(score, mx);
        return;
    } else if (floor <0){
        return;
    }
    if (count == 2){
        temp = score;
        game(floor-2, 1);
        score = temp;
    } else {
        temp = score;
        game(floor-1, count+1);
        score = temp;

        temp = score;
        game(floor-2, 1);
        score = temp;
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i+1];
    game(n, 0);
    cout<< mx;
}