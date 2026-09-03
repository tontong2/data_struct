#include <iostream>
#include <list>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; // 테스트케이스 수
    cin >> t; 

    for(int tc= 0; tc <t; tc++){

    list<char> L; // 명령어 입력 저장
    // 입력을 저장 
    string str;
    cin >> str;

    
    auto cursor = L.begin();
    for(auto c: str){
        if(c == '<'){
            if(cursor != L.begin()){
                cursor--;
            }
        }
        else if(c == '>'){
            if(cursor != L.end()){
                cursor++;
            }
        }
        else if(c == '-'){
            if(cursor != L.begin()){
                cursor--; 
                cursor = L.erase(cursor);
            }
        }
        else{
            cursor = L.insert(cursor, c);
            cursor++;
        }
    }

    for( auto c : L) cout << c;
    cout << "\n";

    }

    return 0;


}
