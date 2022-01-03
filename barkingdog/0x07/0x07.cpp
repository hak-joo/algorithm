#include <iostream>
using namespace std;

const int MX = 1000005;
int dat[2*MX+1];
int head = MX, tail = MX;

void push_front(int x);
void push_back(int x);
void pop_front();
void pop_back();
int front();
int back();

int main(void){

}

void push_front (int x){
    dat[--head] = x;
}
void push_back(int x){
    dat[tail++] = x;
}

void pop_front(){
    head++;
}
void pop_back(){
    tail--;
}

int front(){
    return dat[head];
}

int back(){
    return dat[tail-1];
}