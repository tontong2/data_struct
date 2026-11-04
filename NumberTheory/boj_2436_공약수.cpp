#include<bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0);

typedef long long ll;

// 18 30 > 12 18
ll getGcd(ll a, ll b){
    while(a != 0){
        ll tmp = b % a;
        b = a;
        a = tmp;
    }
    return b;
}

int main(void){
    ll G; ll L;
    ll a; ll b; 
    cin >> G >> L;

    ll N = L/G;
    ll x=1, y = N;

    for(ll i=1; i*i < N; i++){
        if(N % i != 0) continue;

        ll j = N/i;

        if(getGcd(i, j) == 1){
            x = i;
            y = j; 
        }
    }

    cout << G*x << " " << G * y << '\n';
    
    return 0;
}