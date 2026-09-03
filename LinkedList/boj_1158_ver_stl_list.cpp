#include<iostream>
#include <list>
#include <vector>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);


    list<int> L; 
    int n; // n번 까지
    cin >> n;
    int k; // 삭제할 것
    cin >> k;

    vector<int> answer;

    for(int i=1; i<=n; i++){
        L.push_back(i);
    }

    auto cursor = L.begin();

    while(!L.empty()){
        
        for(int i=0; i<k-1; i++){
            cursor++;
            if(cursor == L.end()){
                cursor = L.begin();
            }
            
        }

        answer.push_back(*cursor);
        cursor = L.erase(cursor);
        
        if(cursor == L.end() && !L.empty()){
            cursor = L.begin();
        }
        
    }

    for(auto d: answer){
        cout << d << " ";
    }

    return 0; 
    
}
