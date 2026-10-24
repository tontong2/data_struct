#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)

// n명 n개의 깃발 n번째 선수가 n의 배수의 깃발을 뒤집는다. 백색이 위로 놓인 깃발의 개수가 몇개? 
// 청색(0) -> 백색(1) -> 청색 
// n은 최대 21억

//     1  2  3  4  5  6    (깃발)
//처음 0  0  0  0  0  0   
//1번  1  1  1  1  1  1  
//2번     0     0     0     
//3번        0        1        
//4번           1              
//5번              0             
//6번                 0    (2개)  

// 깃발을 뒤집는 것은 그 번호의 약수의 갯수다 
// 마지막으로 뒤집히려면 약수의 개수가 홀수여야만 백색이 된다. 


#define INF 2.1e9

int count(long n){
    int cnt = 0;
    for(int i=1; i<=n; i++){
        if(n%i == 0) cnt++;
    }
    return cnt;
}

//제곱수를 찾는 함수 
int count2(long n){
    int cnt = 0;
    for(int i=1; i*i<=n; i++){
        cnt++;
    }
    return cnt;
}

int main(void){
    fastio;

    long long n;
    cin >> n; 

    long long answer = 0;
    answer = count2(n);
    cout << answer << "\n";

}