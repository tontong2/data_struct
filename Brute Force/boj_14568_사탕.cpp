#include <bits/stdc++.h>
using namespace std;

// 친구 3명에게 사탕을 나눠 준다.
// 조건은 다음과 같다.
// 1. 남는 사탕이 없어야 함
// 2. 가는 나보다 2개 이상 더 많이 가져야 함
// 3. 세명중 사탕을 못 받는 사람은 없다.
// 4. 다가 갖는 사탕의 개수는 짝수이다.
// 분배 가능한 경우의 수는 ? 


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; // 사탕의 개수
    cin >> n;

    int answer = 0;

    for(int a=0; a<n+1; a++){
        for(int b=0; b<n+1; b++){
            for(int c=0; c<n+1; c++){
                if(a + b + c == n){
                    if(a >= 2+b){
                        if(a!=0 && b!=0 && c!=0){
                            if(c % 2 == 0){
                                answer++;
                            }
                        }
                    }
                } 
            }
        }
    }

    cout << answer;
    return 0;
}