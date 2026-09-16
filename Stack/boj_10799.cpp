#include <iostream>
#include <stack>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    stack<char> s; 
    string a;
    getline(cin, a);
    int count = 0;
    char prev;
    
    for(auto c: a){
        if(c == '('){
            s.push(c);
        }else if(c == ')'){
            s.pop();
            if(prev == '('){
                 count += s.size(); 
            }else{
                count += 1;
            }
        }

        prev = c;
    }

    cout << count << "\n";
    return 0; 
}