
#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    vector<int>::iterator iter; 
    for(iter = num_list.end()-1; iter>= num_list.begin(); iter--){
        answer.push_back(*iter);
    }
    return answer;
}

int sol2(vector<string> s1, vector<string> s2){
    int answer = 0; 
    unordered_set<string> s2_set(s2.begin(), s2.end());

    for(string str: s1){
        if(s2_set.find(str) != s2_set.end()){
            answer++;
        }
    }
    return answer;
}

int main(void){
      ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      vector<int> v; 
  for(int i = 1; i <= 5; i++){
	v.push_back(i);
  }
  solution(v);
}