#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int m;
    cin >> m; 

    vector<int> target; // 삭제할 숫자 저장
    deque<int> dq; 

    for(int i=0; i<m; i++){
        int n;
        cin >> n;
        target.push_back(n);
    }

    for(int i=1; i<=n; i++){
        dq.push_back(i);
    }

    int count = 0; // 연산 값 저장 
    

    for(int i=0; i<m; i++){
        // 덱에서 뽑으려는 숫자의 위치 찾기
        int idx = distance(dq.begin(), find(dq.begin(), dq.end(), target[i]));
        int move = dq.size() - idx;

        // 중간 지점 또는 중간 지점 보다 원소가 앞에 위치한다면
        if(idx <= move){
            // idx 보다 앞에 있는 모든 원소를 뒤로 보냄 (2번쨰 연산)
            for(int j=0; j<idx; j++){
                int temp = dq.front();
                dq.pop_front();
                dq.push_back(temp); 
                count++;
            }
        }else{
            for(int j=0; j<move; j++){
                int temp = dq.back();
                dq.pop_back();
                dq.push_front(temp);
                count++;
            }
            
        }
        dq.pop_front(); 
       
    }

    cout << count << "\n";

}