#include <iostream>
#include <algorithm>

using namespace std;

const int MX= 10000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;

void insert(int addr, int num){
    dat[unused] = num;
    pre[unused] = addr;
    nxt[unused] = nxt[addr];
    if(nxt[addr] != - 1) pre[nxt[addr]] = unused;
    nxt[addr] = unused;
    unused++;
}

void erase(int addr){
    dat[addr] = -1;
    nxt[pre[addr]] = nxt[addr];
    if(nxt[addr] != 1) pre[nxt[addr]] = pre[addr];

}

void traverse();

void insert_test();
void erase_test();

int main(){
    fill(pre, pre+MX, -1);
    fill(nxt, nxt+MX, -1);
    insert_test();
    erase_test();


}