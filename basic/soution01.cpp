#include <stdio.h>
#include <math.h>



// 복잡도는 O(N)
void func1(int n){
    int answer = 0;
    for(int i=0; i<n; i++){
        if(i%3 == 0 || i%5 == 0){
            answer += i;
        }
    }
    printf("%d\n", answer);
}

// N<1000;
// 시간복잡도 n^2
int func2(int arr[], int N){
    for(int i=1; i<N-1; i++){
        for(int j=0; j<N; j++){
            if(arr[j] + arr[i] == 100){
                return 1;
            }
        }
    }
    return 0;
      
}

// 시간복잡도 O(루트N)
int func3(int N){
    for(int i=1; i*i <= N; i++){
        if(i*i == N) return 1;
    }
    return 0;
}

int func4(int N){
    int val = 1;
    while(2*val <= N) val *= 2;
    return val;
}

int main(void){
    int result = 0;
    int n = 1024;
    int arr[] = {4, 13, 63, 87};
    result = func4(n);
    printf("%d\n", result);
    return 0;
}