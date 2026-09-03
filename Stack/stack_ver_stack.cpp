#include <iostream>
#include <stack>

using namespace std;

int main(void){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout <<s.size() << " ";
    
    s.pop();
    cout<<s.top() << "  ";
    s.pop();
    cout << s.top() << " ";

    return 0; 
}