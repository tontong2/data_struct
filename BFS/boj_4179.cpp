#include <iostream>
#include <queue>
 
using namespace std;

#define X first
#define Y second
int r, c; // 행, 열
char board[1000][1000];
int dist[1000][1000];
int j_dist[1000][1000];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c;
    queue<pair<int, int>> Q;
    queue<pair<int, int>> J;

    for(int i=0; i<r; i++){
        fill(dist[i], dist[i]+c, -1);
        fill(j_dist[i], j_dist[i]+c, -1);
    }

    for(int i=0; i<r; i++){
        cin >> board[i];
    }

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            // 불 난 곳을 시작점으로 함
            if(board[i][j] == 'F'){
                Q.push({i, j});
                dist[i][j] = 0;
            }
            // 지훈이의 위치를 시작점으로
            if(board[i][j] == 'J'){
                J.push({i, j});
                j_dist[i][j] = 0;
            }
        }
    }

    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir]; 
            if(nx <0 || nx >= r || ny <0 || ny >= c) continue;
            if(dist[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }

    while(!J.empty()){
        auto cur = J.front(); J.pop();
        for(int dir=0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx <0 || nx >= r || ny <0 || ny >= c) {
                // 범위를 벗어난 것은 탈출했다는 것
                cout << j_dist[cur.X][cur.Y] + 1 << "\n";
                return 0;
            }
            if(j_dist[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            if(dist[nx][ny] != -1 && dist[nx][ny] <= j_dist[cur.X][cur.Y] +1) continue;
            j_dist[nx][ny] = j_dist[cur.X][cur.Y]+1;
            J.push({nx, ny});
            
        }
    }


    cout << "IMPOSSIBLE" << "\n";
}
