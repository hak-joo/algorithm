#include <iostream>

using namespace std;

int n, m;
int arr[100002];
int d[100002];
int st, ed;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin>> arr[i];
        d[i] = d[i-1] + arr[i];
    }
    
    while(m--){
        cin >> st >> ed;
        cout<< d[ed] - d[st-1] <<"\n";
    }

}