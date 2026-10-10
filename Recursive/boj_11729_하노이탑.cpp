#include <bits/stdc++.h>
using namespace std;


// 재귀를 통해 가장 작은 단위로 들어감
// a에서 b로 원판을 이동하는 경우를 따라 이동해야하ㅏㄹ 원판이 1개가 되면 나가ㅏ

void hanoi(int a, int b, int n){
    // 종료 조건 
    if(n == 1){
        cout << a << ' ' << b << '\n';
        return;
    }

    // 하노이탑의 전체 기둥은 1, 2, 3 이므로 전체 탑은 6개
    // a(1)에서 6-1-3 = 2 으로 이동한다 n-1만큼을 (1, 2, n-1)
    hanoi(a, 6-a-b, n-1);

    // 옮기면 출력
    cout << a << ' ' << b << '\n';
    
    // b에서 다시 c로 옮기게 재귀호출
    hanoi(6-a-b, b, n-1);

}


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0); 
    
    int k;
    cin >> k;

    // 1 << K 는 비트연산자로 2^k 승
    cout << (1 << k) -1 << '\n';
    hanoi(1, 3, k); 
    // 1-3으로 이동한다. k만큼의 원판을

}