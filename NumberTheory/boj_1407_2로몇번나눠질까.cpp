#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)

// 2로 몇번까지 나눌 수 있는지 생각해보기, 즉 약수증 2의 거듭제곱이면서 가장 큰 약수를 생각하는 것
// 15는 2로 한번도 나눌 수 없다 = 1 40은 2로 3번까지 나눌 수 있기 떄문에 2^3 = 8이 됨 즉 그 함수를 f(X) 라고 할떄 
// a 이상 b 이하의 모든 자연수에 대해 그 자연수증 모든 약수 중 2의 거듭제곱 꼴이면서 가장 큰 약수들의 총합을 구하는 프로그램
// 즉 f(a) + f(a+1) + ... + f(b)

typedef long long ll;

ll getSum(long long n){
    ll result = n;

    for(ll i=2; i<=n; i*=2){
        result += (n/i) * (i/2);
    }

    return result;
}


int main(void){
    fastio;

    ll a, b; 
    cin >> a >> b;

    cout << getSum(b)- getSum(a-1);
    return 0;
    
}