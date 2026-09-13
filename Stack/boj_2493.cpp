#include <iostream>
#include <stack>
#include <vector> 
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    stack<pair<int, int>> s; 
    vector<int> answer; 

    for(int i=1; i<=n; i++){
        int ch; 
        cin >> ch; 
        s.push({i, ch});
        
    }

    //69574

    for(auto x: answer){
        cout << x << " ";
    }

    return 0;
}