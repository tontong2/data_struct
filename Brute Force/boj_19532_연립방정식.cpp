#include <bits/stdc++.h>
using namespace std;

// ax + by = c
// dx + ey = f
// x와 y값을 찾기
// 범위는 -10000 ~ 10000

// 완전 탐색적으로 생각하기 전체 경우를 다 찾는다. 


int a, b, c, d, e, f;


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> c >> d >> e >> f; 

    for(int x=-10000; x<=10000; x++){
        for(int y = -10000; y<=10000; y++){
            if(a*x + b*y == c){
                if(d*x + e*y == f){
                    cout << x << " " << y;
                    break;
                }
            }
        }
    }

    return 0;

}