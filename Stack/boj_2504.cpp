#include <iostream>
#include <stack>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string a;
    getline(cin, a);

    stack<char> s; 
    int total = 1;
    int answer = 0;
    bool isValid = true;
    char prev = 0;
    
        for(auto c : a){
            if(c == '(' || c == '['){
                s.push(c);
                if(c == '('){
                    total *= 2;
                }else{
                    total *= 3;
                }
            }
            else if(c == ')'){
                if(s.empty() || s.top() != '('){
                    isValid = false;
                    break;
                }
                s.pop();
                if(prev ==  '('){
                answer += total;
                }
                  total /= 2;
            }
            else if(c == ']'){
                if(s.empty() || s.top() != '['){
                    isValid = false;
                    break;
                }
                s.pop();
                if(prev =='['){
                answer += total;
                }
                 total /= 3;
            }

            prev = c;
        }
        if(!s.empty()) isValid = false;
        if(!isValid) answer = 0;
        cout << answer << "\n";
    }
