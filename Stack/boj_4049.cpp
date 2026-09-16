#include <iostream>
#include <stack>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(true){
        string a;
        getline(cin , a);
        if(a == ".") break;
        stack<char> s;
        bool isValid = true;
        for(auto c : a){
            if(c == '(' || c == '['){
                s.push(c);
            }
            else if(c == ')'){
                // s.empty() true일 경우 뒤의 식을 확인 하지 않고 if 문 내로 들어가기 때문에 에러방지
                // Short-Circuit evaluation
                if(s.empty() || s.top() != '('){
                    isValid = false;
                    break;
                }
                s.pop();
            }
            else if(c == ']'){
                if(s.empty() || s.top() != '['){
                    isValid = false;
                    break;
                }
                s.pop();
            }
        }
        if(!s.empty()) isValid = false;
        if(isValid) cout << "yes\n";
        else cout << "no\n";

    }
}