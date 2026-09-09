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

    while(!s.empty()){
        int target_h = s.top().second;
        s.pop();
        stack<pair<int, int>> copy = s;
        while(!copy.empty()){
            int before_h = copy.top().second; 
            if(target_h <= before_h){
                answer.push_back(copy.top().first);
                copy.pop();
                break;
            }else{
                copy.pop();
            }
        }
        if(copy.empty()){
            answer.push_back(0);
        }
    }

    for(auto x: answer){
        cout << x << " ";
    }

    return 0;
}