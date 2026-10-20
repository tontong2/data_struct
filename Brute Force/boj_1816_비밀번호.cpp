#include <bits/stdc++.h>
using namespace std;

// 모든 소인수가 1,000,000 보다 크면 적절한 비번이다.
// 생각의 전환으로 틀린 비번을 찾으면 더 쉽다. 왜냐? 백만 보다 작은 소인수를 가지면 그것은 틀렸으므로,

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int TC;
    cin >> TC;

    for(int i=0; i<TC; i++){
        long long target;
        cin >> target;

        for(int j=2; j<=1000000; j++){
            if(target % j == 0) { 
                cout << "No\n";
                break;
            }
            else if(j == 1000000){
                cout << "Yes\n";
                break;
            }
        }
       
    }
    return 0;
}

// 모든 경우의 수를 탐색한다.
// 항상 정수를 선언할 때는 해당 값이 가지는 최대값을 고려한다. (long long 말고 int 를 쓰면 오류가 남)

