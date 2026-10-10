#include <bits/stdc++.h>
using namespace std;


int paper[128][128]; 
int white, blue; 





// 값이 다를경우 9등분 하는 재귀함수
void divide(int a, int b, int n){

    // 잘라야 할지 
    bool cut = false;
    int save = paper[a][b];
    for(int i=a; i<a+n; i++){
        for(int j=b; j<b+n; j++){
            if(paper[i][j] != save) cut = true; 

        }
    }

    // 값이 같으면
    if(cut) {
        divide(a, b, n/2);
        divide(a, b+n/2, n/2);
        divide(a+n/2, b, n/2);
        divide(a+n/2 , b+n/2, n/2);
    }
    else{
        if(save == 1) blue++;
        else white++; 
    }


}




int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 한변의 길이 
    int n;
    cin >> n; 

    // 하얀색은 0 , 파란색은 1
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> paper[i][j]; 
        }
    }

    divide(0, 0, n);
    cout << white << '\n' << blue << '\n';


}

