#include <iostream>
#include <queue>

using namespace std;

#define X first 
#define Y second    

int n;
char board[1000][1000];
int dist[1000][1000];
int fire[1000][1000];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int TC;

queue<pair<int, int>> Q;
queue<pair<int, int>> F;


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> TC;

    for(int i=0; i<TC; i++){
        int w, h; 

        // 열, 행
        cin >> w >> h; 

        while(!Q.empty()) Q.pop();
        while(!F.empty()) F.pop();    

        for(int i=0; i<h; i++){
            fill(dist[i], dist[i]+w, 0); 
            fill(fire[i], fire[i]+w, 0); 
        }

        for(int i=0; i<h; i++){
            cin >> board[i]; 
        }

        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                // 불 난 곳
                if(board[i][j] == '*'){
                    F.push({i, j});
                    fire[i][j] = 1;
                }
                // 상근이 
                if(board[i][j] == '@'){
                    Q.push({i, j});
                    dist[i][j] = 1;
                }
            }
        }
       
        // 불 
        while(!F.empty()){
            auto cur = F.front(); F.pop();
            for(int dir = 0; dir<4; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir]; 
                // 범위를 벗어난 경우 제외
                if(nx <0 || nx >= h || ny <0 || ny >= w) continue;
                // 불이 난 적이 있고, 벽인 경우 제외
                if(fire[nx][ny] > 0 || board[nx][ny] == '#') continue;
                fire[nx][ny] = fire[cur.X][cur.Y] + 1;
                F.push({nx, ny});
            }
        }

        bool escaped = false;

        // 상근이
        while(!Q.empty()){
            auto cur = Q.front(); Q.pop(); 
            for(int dir=0; dir<4; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir]; 
                // 범위를 벗어난 경우 = 즉 탈출
                if(nx <0 || nx >= h || ny <0 || ny >= w){
                    cout << "답: " << dist[cur.X][cur.Y] << "\n";
                    escaped = true;
                    break;
                }
                // 상근이가 방문했었고, 벽인 경우 제외
                if(dist[nx][ny] > 0 || board[nx][ny] == '#' ) continue;
                // 이미 불났거나 상근이가가 갈 시간보다 불이 먼저 난 경우
                if(fire[nx][ny] != 0 && dist[cur.X][cur.Y]+1 >= fire[nx][ny]) continue;
                dist[nx][ny] = dist[cur.X][cur.Y] +1;
                Q.push({nx, ny});

            }

            if(escaped) break;
        }

        if(!escaped) cout << "IMPOSSIBLE" << "\n";

        
    }

    
}


