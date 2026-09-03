#include <iostream>
#include <stack>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    stack<int> s; 
    int k;
    cin >> k;

    int total = 0;
    for(int i=0; i<k; i++){
        int n;
        cin >> n;
        
        if(n != 0){
            s.push(n);
        }else{
            if(!s.empty()){
                s.pop();
            }
        }
    }

    while(!s.empty()){
    total += s.top();
    s.pop();
    }

    cout << total << "\n";
    return 0; 

}