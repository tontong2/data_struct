#include <iostream>
#include <queue>
using namespace std;

int main(void){
    queue<int> Q;
    Q.push(10);
    Q.push(20);
    Q.push(30);
    cout << Q.size() << "\n";
    Q.pop();
    cout << Q.back() << "\n";

    return 0;
}