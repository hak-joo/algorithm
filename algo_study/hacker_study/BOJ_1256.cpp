#include <iostream>
#include <string>

using namespace std;

long long DP[201][101];

int N, M;
long long K;

string ans(){
    string answer = "";
    K--;
    if(DP[N+M][M] <= K){
        return "-1";
    } else{
        for(int i= N+M-1; i>=0; i--){
            if(i >= M && DP[i][M] > K){ //a가 더 채워져야함
                answer += 'a';
            } else{ //z가 들어가야함
                answer += 'z';
                K -= DP[i][M];
                M--;
            }
        }
    }
    return answer;
}

void calcDP(){
    DP[0][0] = 1;
    for(int i=1; i<=N+M; i++){
        DP[i][0] = 1;
        for(int j=1; j<=M; j++){
            if(i==j) DP[i][j] = 1;
            else{
                DP[i][j] = DP[i-1][j] + DP[i-1][j-1];
                if(DP[i][j] >= 1000000000) DP[i][j] = 1000000000;
            }
        }
    }
}

int main(void){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> N >> M >> K;
    calcDP();
    string answer = ans();
    cout << answer;
}