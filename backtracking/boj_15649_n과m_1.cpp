#include <bits/stdc++.h>
using namespace std;

int n, m; 

// 방문한 노드라면 다음 노드를 탐색하도록 N크기의 bool 배열이 필요    
bool vis[8];
// 탐색 과정에서 값을 담을 int 배열이 필요.
int save[8];


// 중복을 제외한 모든 경우의 수를 탐색하자.
void dfs(int depth){
    if(depth == m){
        for(int i=0; i<m; i++){
            cout << save[i] << ' ';
        }
        cout << '\n';
        return; 
    }

    for(int i=0; i<n; i++){
        if(!vis[i]){
            vis[i] = 1;
            save[depth] = i+1;
            dfs(depth+1);

            vis[i] = false;
        }
    }

    return;
}


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m; 

    dfs(0);


   

}