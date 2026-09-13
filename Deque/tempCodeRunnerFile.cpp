#include <iostream>
#include <deque>
#include <vector>
#include <cctype>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;

    while(tc--){

            deque<int> dq;
    string answer; 

    string p;
    cin >> p; 

    int n;
    cin >> n;

    string s;
    cin >> s;

        int num;

    if(s != "[]"){
        num = 0; 
    }

    for(int i=0; i<s.length(); i++){
        if(isdigit(s[i])){
            num = num * 10 + (s[i] - '0');
        }
        else if(s[i] == ',' || s[i] == ']'){
            dq.push_back(num);
            num = 0; 
        }
    }

    bool reversed = false; 
    bool error = false;  

    for(int i=0; i<p.length(); i++){
        if(p[i] == 'R'){
            reversed = !reversed;
        }
        else if(p[i] == 'D'){
            if(dq.empty()){
                error = true;
                break;
            }

            if(reversed){
                dq.pop_back();
            }
            else{
                dq.pop_front();
            }
        }
    }

    if(error){
        cout << "error\n";
        continue; 
    }

    cout << "[";

    if(!reversed){
        for(int i=0; i<dq.size(); i++){
            if(i>0) cout << ",";
            cout << dq[i];
        }
    }else{
        for(int i= dq.size() -1; i>=0; i--){
            if(i < dq.size()-1) cout << ",";
            cout << dq[i];
        }
    }

    cout << "]\n";

    }

    return 0; 
}