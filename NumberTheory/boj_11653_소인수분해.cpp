#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)

int main(void){
    fastio;

    long long n;
    cin >> n;
    int num = 2;  

    while(n > 1){
      
        if(n % num == 0){
            n = n/num; 
            cout << num << '\n';
        }
        else{
            num++;
        }
    }

}