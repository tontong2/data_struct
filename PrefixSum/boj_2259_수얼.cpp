#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0);

// 어떤 정수의 수열이 있을 때 연속적인 며칠 동안의 온도합이 가장 큰 값을 알아보자

int arr[100000];
int prefix[100001];
int answer[100001];

int main(void){
    fastio;

    int N; // 전체 날짜 
    int K; // 연속 날짜수 
    cin >> N >> K;
    

    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    for(int i=0; i<N; i++){
        prefix[i+1] = prefix[i] + arr[i];
    }

    int cnt = 0; 
    for(int i = K; i <= N; i++){
        answer[cnt++] = prefix[i] - prefix[i-K];
    }

    int result = answer[0];

    for(int i = 1; i < cnt; i++){
        if(answer[i] > result){
            result = answer[i];
        }
    }

    cout << result << '\n';
    return 0;
}