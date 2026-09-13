#include <iostream>
using namespace std;

int main(void){
    deque<int> DQ;
    
    DQ.push_front(10);
    DQ.push_back(20);
    DQ.push_front(24);
    for(auto x: DQ){
        cout << x << " ";
    }
    cout << DQ.size() << "\n"; 
    DQ[2] = 17;
    DQ.insert(DQ.begin()+1, 33);
    DQ.erase(DQ.begin()+3);
    DQ.clear();
}