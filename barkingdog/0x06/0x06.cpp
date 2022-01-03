#include <iostream>

using namespace std;

const int MX = 100005;
int dat[MX];
int head = 0, tail = 0;

void push(int x);
void pop();
int front();
int back();

int main(void){
    //this is non STL queue
}

void push(int x){
    dat[head++] = x;
}

void pop(){
    if (tail - head !=0 ) cout<<dat[head++];
}

int front(){
    return dat[head];
}

int back(){
    return dat[tail - 1];
}

