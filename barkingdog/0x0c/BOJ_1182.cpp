#include <iostream>
#include <vector>

using namespace std;

int n, s;
int arr[21];
int sum = 0;
int cnt = 0;

void func(int k, int sum);

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    if(s == 0) cnt--;
    func(0, sum);
    cout<<cnt;
}

void func(int k, int sum){
    if(k ==n){
        if (sum == s) cnt++;
        return;
    }
    func(k+1, sum); //값을 안 넣었을 때 
    func(k+1, sum + arr[k]);
 
}
