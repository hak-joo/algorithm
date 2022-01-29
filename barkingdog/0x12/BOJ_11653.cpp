#include <iostream>
#include <vector>

using namespace std;

int n;
int cur;
vector<int> result;
int main(void)
{
    cin >> n;
    for(int i=2; i*i<=n; i++){
        while(n%i ==0){
            cout<<i<<"\n";
            n/=i;
        }
    }

    if(n!=1) cout << n;
}