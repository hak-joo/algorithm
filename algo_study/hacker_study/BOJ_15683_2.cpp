#include <iostream>
#include <algorithm>
using namespace std;

struct Camera{
    int x;
    int y;
    int type;
};

int N, M;
int cant[8][8];
int arr[8][8];
int rotation[5] = {4, 2, 4, 4, 1};
int minimum = 9999999;

Camera cam[8];
int camera_num = 0;

void copy(int origin[8][8], int copied[8][8]){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            copied[i][j] = origin[i][j];
        }
    }
}


void mark(int dir, int idx){
    dir = (dir % 4);
    if(dir == 0){ //동
        for (int x= cam[idx].x; x < M; x++){
            if(arr[cam[idx].y][x] == 6) break;
            cant[cam[idx].y][x] = 1;
        }
    } else if (dir == 1){ // 북
        for(int y= cam[idx].y; y<N; y++){
            if(arr[y][cam[idx].x] == 6) break;
            cant[y][cam[idx].x] = 1;
        }
    } else if (dir == 2) {//서
        for(int x = cam[idx].x; x >=0; x --){
            if(arr[cam[idx].y][x] == 6) break;
            cant[cam[idx].y][x] = 1;
        }
    } else if (dir == 3) { //남
        for(int y= cam[idx].y; y>=0; y--){
            if(arr[y][cam[idx].x] == 6) break;
            cant[y][cam[idx].x] = 1;
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

void func(int k){
    if(k == camera_num){
        calc();
        return;
    }
    else{
        int temp[8][8];
        for (int dir=0; dir<rotation[cam[k].type-1]; dir++){
            copy(cant, temp);
            if(cam[k].type == 1){
                mark(dir, k);
                func(k+1);
            } else if (cam[k].type == 2){
                mark(dir, k);
                mark(dir+2, k);
                func(k+1);
            } else if (cam[k].type == 3){
                mark(dir,k);
                mark(dir+1,k);
                func(k+1);
            } else if (cam[k].type == 4){
                mark(dir,k);
                mark(dir+1,k);
                mark(dir+2,k);
                func(k+1);
            } else if (cam[k].type == 5){
                mark(dir,k);
                mark(dir+1,k);
                mark(dir+2,k);
                mark(dir+3, k);
                func(k+1);
            }
            copy(temp, cant);
        }
    }

}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
            if(1 <= arr[i][j] && arr[i][j] <=5){
                cant[i][j] = 1;
                cam[camera_num].x = j;
                cam[camera_num].y = i;
                cam[camera_num].type = arr[i][j];
                camera_num++;
            } else if (arr[i][j] == 6) cant[i][j] = 1;
        }
    }
    func(0);
    cout << minimum;
}

