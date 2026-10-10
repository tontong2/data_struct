#include <bits/stdc++.h>

using namespace std;

int total = 0; 

// 재귀로 N부터 1까지 출력하는 함수
void func1(int N){
    if(N == 0) return;
    cout << N << "\n";
    return func1(N-1);
}

// 재귀로 1부터 N까지의 합을 구하는 함수
void func2(int N){
    if(N == 0){
        cout << total << "\n";
        return; 
    } 
    total += N;
    return func2(N-1);
}


//  ab mod m 을 구해라
// 6, 100, 5  6^100 % 5 = 6 % 5
long long func3(int a, int b, int m){
    long long val = 1;
    while(b--) val = val * a % m;
    return val;
}

int main(void){
    int N = 3;
    //func1(N);
    cout << "\n";
    cout << func3(6, 100, 5);
    
    return 0;
}

