#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)

// 보석을 여러개 훔치면 보석의 무게가 모든 보석의 곱이 되어버림
// 그냥 차라리 많이 가져오자 효빈이가 최대로 들수 있는 무게 만큼
// 효빈이는 k만큼 들수 있기 때문에 k만큼의 최대 보석 갯수


#define K 1e12

int main(void){
    fastio;

    long long n;
    cin >> n;

    long long cnt = 0;
    vector<long long> factors;

    for(long long i=2; i*i <= n; i++){
        while(n % i == 0){
            factors.push_back(i);
            n = n/i;
        }
    }
    
    if(n > 1){
        factors.push_back(n);
    }

    cout << factors.size() << '\n';
    for(auto x : factors){
        cout << x << ' ';
    }
}