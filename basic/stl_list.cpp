#include <iostream>
#include <list>

using namespace std;

int main(void){
    list<int> L  = {1, 2};
    // list<int>::iterator 
    auto t = L.begin(); // t는 시작원소인 1을 가리킴
    L.push_front(10);  // 10, 1, 2 
    cout << *t << '\n'; // t가 가리키는 값 출력 = 1
    L.push_back(5); // 10, 1, 2, 5
    L.insert(t, 6); // 10, 6, 1, 2, 5 (t가 가리키는 값 앞에 추가)
    t++; // t를 한칸 전진 t = 2
    t = L.erase(t); // t가 가리키는 값을 제거 (10, 6, 1, 5) 이제 t는 5

    cout << *t << '\n';
    for(auto i : L) cout << i << ' ';
    cout << '\n';
    for(auto it = L.begin(); it != L.end(); it++){
        cout << *it << ' ';
    }


    
}