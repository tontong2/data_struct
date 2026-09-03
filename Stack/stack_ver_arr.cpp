#include <iostream>

using namespace std;

const int MX = 100005;
int dat[MX]; 
int pos = 0;

void push(int x){
    dat[pos++] = x;
}

void pop(){
    pos--;
}

int top(){
    return dat[pos-1];
}

void test(){
    push(10);
    push(20);
    push(30);
    pop();
    
}

int main(void){
    test();
    return 0; 
}
