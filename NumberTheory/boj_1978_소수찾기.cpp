#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)

// 주어진 수 N개 중에서 소수가 몇 개 인지 찾아서 출력하는 프로그램을 작성
// N 은 100이하 N개의 수는 1000이하

int main(void){
    fastio;

    int n;
    cin >> n;

    int answer = 0;

    for(int i=0; i<n; i++){
        int num; 
        cin >> num;

        if(num < 2) continue;
        
        bool isPrime = true;

        for(int j=2; j*j <=num; j++){
            if(num%j == 0){
                isPrime = false;
                break;
            }
        }

        if(isPrime) answer++;
    }
    
    cout << answer << '\n';

}