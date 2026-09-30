#include <iostream>
#include <queue> 

using namespace std;

#define X first
#define Y second
char board[50][50];
int dist[50][50];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int t, m, n, k;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    for(int tc=0; tc<t; tc++){
        cin >> m >> n >> k; 
        int bug = 0; 

        for(int i = 0; i < n; i++){
            fill(board[i], board[i] + m, 0);
            fill(dist[i], dist[i]+m, 0);
        }

        // 배추의 위치를 입력 받아서 보드를 채우기 
        for(int i=0; i<k; i++){
            int x, y;
            cin >> x >> y;
            board[y][x] = 1;
        }

            
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){

                // 배추가 있거나 이미 방문을 했다면 넘어감
                if(board[i][j] == 0 || dist[i][j]) continue;
            

                // 배추를 찾으면(배추벌레 추가)
                bug++;

                queue<pair<int, int>> Q;

                dist[i][j] = 1;
                Q.push({i, j});

                while(!Q.empty()){
                    pair<int, int> cur = Q.front(); Q.pop();
                    for(int dir=0; dir<4; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir]; 
                        if(nx < 0 || nx >= n || ny<0 || ny >= m) continue;
                        if(dist[nx][ny] || board[nx][ny] != 1) continue;
                        dist[nx][ny] = 1;
                        Q.push({nx, ny});
                    }
                }
                
            }
        }
    cout << "\n" << bug << "\n";
    }
}
