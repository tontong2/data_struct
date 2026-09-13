#include <iostream>
#include <deque>
#include <cctype>
#include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;

    vector<string> answers; // 모든 테스트 케이스의 결과 저장

    while(tc--){

        deque<int> dq;

        string p;
        cin >> p;

        int n;
        cin >> n;

        string s;
        cin >> s;

        int num = 0;

        if(s != "[]"){
            for(int i = 0; i < s.length(); i++){
                if(isdigit(s[i])){
                    num = num * 10 + (s[i] - '0');
                }
                else if(s[i] == ',' || s[i] == ']'){
                    dq.push_back(num);
                    num = 0;
                }
            }
        }

        bool reversed = false;
        bool error = false;

        for(int i = 0; i < p.length(); i++){
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
            answers.push_back("error");
            continue;
        }

        string result = "[";

        if(!reversed){
            for(int i = 0; i < dq.size(); i++){
                if(i > 0) result += ",";
                result += to_string(dq[i]);
            }
        }
        else{
            for(int i = dq.size() - 1; i >= 0; i--){
                if(i < dq.size() - 1) result += ",";
                result += to_string(dq[i]);
            }
        }

        result += "]";

        answers.push_back(result);
    }

    // 모든 테스트 케이스가 끝난 후 한꺼번에 출력
    cout << "\n";
    for(string result : answers){
        cout << result << "\n";
    }

    return 0;
}