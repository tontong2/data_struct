#include <iostream>
#include <queue>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n; 

    queue<int> Q;

    // 1 부터 n까지 번호 넣기
    for(int i=1; i<=n; i++){
        Q.push(i);
    }
    
    while(Q.size() != 1){
        Q.pop(); 
        int top = Q.front();
        Q.pop();
        Q.push(top);
        
    }

    cout << Q.front() << "\n";
}
