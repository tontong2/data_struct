#include <bits/stdc++.h>
using namespace std;


// a를 b번 곱한 수를 c로 나눈 나머지를 구하는 함수
// a^b % c;
long long func(long long a, long long b, long long c){
    long long val = 1;
    while(b--){
        if(b == 0) break; 
        val = val * a * b;
    }
    return val % c;
}

long long func2(long long a, long long b, long long c){
    // 0번 곱할 경우 
    if(b == 0) return 1;
    // 1번 곱할 경우
    if(b == 1) return a % c;

    long long k = func2(a, b/2, c) % c;

    // 지수가 짝수이면
    if(b % 2 == 0) return k*k%c;
    // 지수가 홀수이면
    else return k*k % c * a %c;
}



int main(void){
    long long total = 0; 
    long long a; long long b; long long c;
    
    cin >> a >> b >> c;

    cout << func2(a, b, c) << "\n";
}