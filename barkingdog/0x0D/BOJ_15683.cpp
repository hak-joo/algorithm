#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int N, M; // 세로, 가로 크기
int minimum = 999999;

int camera_num = 0;

struct Camera{
    int x,y, type;
};

Camera cam[8];

int arr[8][8];
int cant[8][8];
int temp[8][8];
void func(int k);
void calc();
void mark(int k, int dir);

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
            if(1<= arr[i][j] && arr[i][j] <=5) {
                cant[i][j] = 1;
                cam[camera_num].x = j;
                cam[camera_num].y = i;
                cam[camera_num].type = arr[i][j]; 
                camera_num++;
            }
            if (arr[i][j] == 6) cant[i][j] = 1;
        }
    }
    func(0);
    cout<<minimum;
}

void copy(int origin[8][8], int copied[8][8]){
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            copied[i][j] = origin[i][j];
        }
    }
}

void func(int k){
    bool brk = false;
    int temp[8][8];

    if(k == camera_num){
        calc();
        brk = true;
        return;
    }
    if(cam[k].type == 1){
        copy(cant, temp);
        mark(k, 0);
        func(k+1);
        copy(temp, cant);

        copy(cant, temp);
        mark(k, 1);
        func(k+1);
        copy(temp, cant);

        copy(cant, temp);
        mark(k, 2);
        func(k+1);
        copy(temp, cant);

        copy(cant, temp);
        mark(k, 3);
        func(k+1);
        copy(temp, cant);

    } 
    else if (cam[k].type == 2){
        copy(cant, temp);
        mark(k,0); mark(k,1);
        func(k+1);
        copy(temp, cant);

        copy(cant, temp);
        mark(k,2); mark(k,3);
        func(k+1);
        copy(temp, cant);

    } else if (cam[k].type == 3){
        copy(cant, temp);
        mark(k,0); mark(k,2);
        func(k+1);
        copy(temp, cant);

        copy(cant, temp);
        mark(k,1); mark(k,3);
        func(k+1);
        copy(temp, cant);

        copy(cant, temp);
        mark(k,0); mark(k,4);
        func(k+1);
        copy(temp, cant);

        copy(cant, temp);
        mark(k,2); mark(k,3);
        func(k+1);
        copy(temp, cant);

    } else if (cam[k].type == 4){
        copy(cant, temp);
        mark(k,0); mark(k,1); mark(k,2);
        func(k+1);
        copy(temp, cant);
        
        copy(cant, temp);
        mark(k,1); mark(k,2); mark(k,3);
        func(k+1);
        copy(temp, cant);
        
        copy(cant, temp);
        mark(k,2); mark(k,3); mark(k,1);
        func(k+1);
        copy(temp, cant);

        copy(cant, temp);
        mark(k,3); mark(k,0); mark(k,1);
        func(k+1);
        copy(temp, cant);
    } else if (cam[k].type == 5){
        copy(cant, temp);
        mark(k,0); mark(k,1); mark(k,2); mark(k,3);
        func(k+1);
        copy(temp, cant);


    }
        

    
}

void mark(int k, int dir){
    if(dir == 0){ // 동쪽
        for(int i=cam[k].x; i<M; i++){
            if(arr[cam[k].y][i] == 6) break;
            cant[cam[k].y][i] = 1;
        }
    } else if (dir == 1){ //서쪽
        for(int i = cam[k].x; i>=0; i--){
            if(arr[cam[k].y][i] < 0 || arr[cam[k].y][i] == 6) break;
            cant[cam[k].y][i] = 1;
        }
    } else if (dir == 2){ //남쪽}
        for(int j=cam[k].y; j<N; j++){
            if(arr[j][cam[k].x] == 6) break;
            cant[j][cam[k].x] = 1;
        }
    } else if (dir == 3){ //북쪽
        for(int j= cam[k].y; j>=0; j--){
            if(arr[j][cam[k].x] < 0 || arr[j][cam[k].x] == 6) break;
            cant[j][cam[k].x] = 1;
        }
    }
}

void calc(){
    int cnt = 0;
    for(int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            if(cant[i][j] == 0) cnt++;
        }
    }
    minimum = min(minimum, cnt);
}
