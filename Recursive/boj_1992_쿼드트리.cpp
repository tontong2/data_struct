#include <bits/stdc++.h>
using namespace std;

char video[65][65]; 
string s; 

// 값이 다를 경우 4등분 하는 재귀함수 
void divide(int n, int r, int c){
    bool cut = false;
    int save = (int)video[r][c];
    for(int i=r; i<r+n; i++){
        for(int j=c; j<c+n; j++){
            if(video[i][j] != save) cut = true; 
        }
    }

    // 값이 다르다면
    if(cut){
        s += '(';
        n = n/2;
        for(int i=0; i<2; i++){
            for(int j=0; j<2; j++){
                divide(n, r+n*i, c+n*j);
            }
        }
        s += ')';
    }

    else{
        s += save;
    }
    
    
}


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; 
    cin >> n; 

    for(int i=0; i<n; i++){
        cin >> video[i];
    }

    divide(n, 0, 0);

    cout << s << '\n';

}
