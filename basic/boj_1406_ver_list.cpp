#include <iostream> 
#include <list> 

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str; // 초기문자열
    cin >> str; 

    list<char> L; // 명령어 입력 저장
    // 초기 문자열을 저장
    for(auto c : str){
        L.push_back(c);
    }
    // 커서는 마지막 위치에
    auto cursor = L.end(); 

    int q; // 명령어 갯수
    cin >> q;

    while(q--){
        char op;
        cin >> op;

        if(op == 'P'){
            char add;
            cin >> add;
            L.insert(cursor, add);
        }
        else if(op == 'L'){
            if(cursor != L.begin()) cursor--;
        }
        else if(op == 'R'){
            if(cursor != L.end()) cursor++;
        }
        else{
            if(cursor != L.begin()){
                cursor--;
                cursor = L.erase(cursor);
            }
        }
    }
    for( auto c : L) cout << c;
    return 0;
}