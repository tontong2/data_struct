#include <bits/stdc++.h>
using namespace std;

int paper[2187][2187];
int mi, zero, one; 


// 값이 다 일치하는지 (하나의 종이인지 판별)
bool same(int a, int b, int n){
    int save = paper[a][b];
    for(int i=a; i<a+n; i++){
        for(int j=b; j<b+n; j++){
            if(paper[i][j] != save) return false; 

        }
    }
    return true;
}


// 값이 다를경우 9등분 하는 재귀함수
void divide(int a, int b, int n){
    // 값이 같으면
    if(same(a, b, n) == true) {
        switch(paper[a][b]){
            case -1: mi++; break;
            case 0: zero++; break;
            case 1: one++; break;
        }
        return;
    }

    // 값이 다르다면(3으로 나눠야함)
    n = n/3;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            divide(a+n*i,b+n*j, n);
        }
    }

}



int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; 
    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> paper[i][j];
        }
    }

    divide(0, 0, n);

    
    cout << "\n" << mi << " " << zero << " " << one << "\n";
}
