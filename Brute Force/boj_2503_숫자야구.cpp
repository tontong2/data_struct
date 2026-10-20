#include <bits/stdc++.h>
using namespace std;

// a는 세자리 숫자
// b는 세자리 숫자를 제시해서 맞추려 한다.
// 제시한 숫자에 정답이 포함되어 있다면 1bull
// 정답이 포함되어 있고 자리도 똑같다면 1strike
// bull 과 strike 만 보고 가능 한 수의 갯수


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int answer = 0;

    int hint[100][3];
    for(int i=0; i<n; i++){
        cin >> hint[i][0] >> hint[i][1] >> hint[i][2];
    }
    
    for(int a=1; a<10; a++){
        for(int b=0; b<10; b++){
            for(int c=0; c<10; c++){
                if(a == b || b == c || a == c) continue;

                int cnt = 0; 
                for(int i=0; i<n; i++){
                    int number, ball, strike;
                    number = hint[i][0];
                    strike = hint[i][1];
                    ball = hint[i][2];

                    int ball_count = 0;
                    int strike_count = 0; 

                    int n1 = number % 10;
                    int n10 = (number /10 ) %10;
                    int n100 = number /100;

                    if (a == n100) strike_count++;
                    if (b == n10) strike_count++;
                    if (c == n1) strike_count++;
                    
                    if (a == n10 || a == n1) ball_count++;
                    if (b == n100 || b == n1) ball_count++;
                    if (c == n100 || c == n10) ball_count++;

                    if(ball == ball_count && strike == strike_count){
                        cnt+=1;
                    }
                }
                if(cnt == n) answer +=1;
            }
        }
    }

    cout << answer << '\n';
}


// a가 정답으로 생각 할 수 있는 모든 수를 넣어본다 100 - 999 까지의 숫자
// b가 도전한 내용이 맞는 지 확인하기
