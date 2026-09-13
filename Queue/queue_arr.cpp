#include <iostream>
using namespace std;

const int MX = 100005;
int dat[MX];
int head = 0, tail = 0;

// 값 추가
void push(int x){
    dat[tail++] = x;
}

void pop() {
    head++;
}

// 가장 앞의 원소를 반환
int front() { 
    return dat[head];
}

int back() {
    return dat[tail-1];
}

void test() {
    push(10); push(20); push(30);
  cout << front() << '\n'; // 10
  cout << back() << '\n'; // 30
  pop(); pop();
  push(15); push(25);
  cout << front() << '\n'; // 30
  cout << back() << '\n'; // 25
}

int main(void) {
    test();
}