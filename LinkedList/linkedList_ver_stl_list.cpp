#include <iostream>
#include <list>

using namespace std;

list<int> L;

int main(void){
    L.push_back(10);
    L.push_back(20);
    L.push_back(40);
    L.push_front(5);
    L.pop_back();


    for(auto it = L.begin(); it != L.end(); it++){
        cout << *it << " ";
    }

}