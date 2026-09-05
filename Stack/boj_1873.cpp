#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> check;
    vector<char> answer;
    stack<int> s;

    // 주어진 수열
    for(int i=0; i<n; i++){
        int ch;
        cin >> ch;
        check.push_back(ch); 
    }

    int input = 1; // 현재 push 할 숫자 값 //전체 프로그램 동안 한번씩만 증가해서 최대 Push 횟수가 N번
    for(int target=0; target<n; target++){
        while(input <= check[target]){
                s.push(input++);
                answer.push_back('+');
            }
        if(!s.empty() && s.top() == check[target]){
            s.pop(); 
            answer.push_back('-');
        }
        else{
            cout << "NO" << "\n";
            return 0;
        }
    }

    for(int i=0; i<answer.size(); i++){
        cout << answer[i] << "\n";
    }
    
    return 0; 
}