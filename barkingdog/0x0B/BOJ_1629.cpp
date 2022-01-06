#include <iostream>

using namespace std;

using ll = long long;

ll POW(ll a, ll b, ll c){
    if (b==1) return a%c;
    ll val = POW(a, b/2, c);
    val = val * val % c;
    if (b%2 == 0) return val;
    else return val * a % c;
}

int main (void){
    ll A, B, C;
    cin >>A >> B >> C;
    cout<<POW(A,B,C);
}