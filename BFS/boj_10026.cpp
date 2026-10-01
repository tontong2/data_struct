#include <iostream>
#include <queue>

using namespace std;

#define X first 
#define Y second    

int n;
char board[101][101];
int vis[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int pub = 0;
int npub = 0;

queue<pair<int, int>> Q; 

void bfs(bool blind){

    char color = board[Q.front().X][Q.front().Y];
    
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();

        for(int dir=0; dir<4; dir++){
            int nx =  cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx <0 || nx >= n || ny <0 || ny >= n) continue;
            if(vis[nx][ny] == 1) continue;

            int ncolor = board[nx][ny];
            bool sameColor; 

            if(blind){
                sameColor = 
                    (color == 'R' || color == 'G') && (ncolor == 'R' || ncolor == 'G') || (color == 'B' && ncolor == 'B');
            }else{
                sameColor = (color == ncolor); 
            }

            if(!sameColor){
                continue;
            }

            vis[nx][ny] = 1;
            Q.push({nx, ny});
        }
    }

    
    if(blind){
        npub++;
    }
    else {
        pub++;
    }
}



int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    string str;

    for(int i=0; i<n; i++){
        cin >> str;
        for(int j=0; j<n; j++){
            board[i][j] = str[j];
        }
    }

    // 색맹아님
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(vis[i][j]) continue;

            vis[i][j] = 1; 
            Q.push({i, j}); 

            bfs(false); 
        }
    }

    // 방문 배열 초기화
    for(int i=0; i<n; i++){
        fill(vis[i], vis[i]+n, 0); 
    }

    // 색맹이면
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(vis[i][j]) continue;

            vis[i][j] = 1; 
            Q.push({i, j}); 

            bfs(true); 
        }
    }

    cout << "answer! \n";
    cout << pub << ' ' << npub << '\n';
    return 0;

}