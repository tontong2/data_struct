#include <bits/stdc++.h>
using namespace std;

// 1. 함수의 정의 : func(int n, int r, int c)
// 2^n 배열에서 (r, c) 를 방문하는 순서를 반환

// 2. base condition 종료조건 
// n == 0 일때 return 0

// 3. 재귀 식
// r.c 가 1번 사각형일 때 return func(n-1, r, c);
// 2번 return half*half + func(n-1, r, c-half);

int func(int n, int r, int c){
    if(n == 0) return 0;
    int half = 1 << (n-1);
    if(r < half && c < half) return func(n-1, r, c);
    else if(r < half && c >= half) return func(n-1, r, c-half) + half*half;
    else if(r >= half && c < half ) return func(n-1, r-half, c) + half*half*2;
    return 3*half*half + func(n-1, r-half, c-half);
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, r, c;
    cin >> n >> r >> c;
    cout << func(n, r, c) << "\n";
}