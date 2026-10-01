#include <iostream>
#include <queue>

using namespace std;

#define X first 
#define Y second 

// 나이트의 이동 방향
int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2}; 

// 보드 
int board[300][300];
int dist[300][300]; 

int result;

void bfs(int I, int start_x, int start_y, int end_x, int end_y){
    queue<pair<int, int> > Q;
    dist[start_x][start_y] = 1;
    Q.push({start_x, start_y});

    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();

        for(int dir=0; dir<8; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir]; 
            

            if(nx <0 || nx >= I || ny <0 || ny >= I) continue;
            if(dist[nx][ny] > 0) continue;
            if(nx == end_x && ny == end_y){
                result = dist[cur.X][cur.Y];
                return;
            }

            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx, ny}); 
        
        }
    }

    return; 
}


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int TC;
    cin >> TC;
    
    for(int tc=0; tc<TC; tc++){
        int I;
        cin >> I;

        int start_x, start_y; 
        int end_x, end_y;

        result = 0; 

        cin >> start_x >> start_y;
        cin >> end_x >> end_y; 

        // 보드 초기화
        for(int i=0; i<I; i++){
            fill(dist[i], dist[i]+I, 0);
        }

        bfs(I, start_x, start_y, end_x, end_y);

        

        cout << "\n" << result << "\n"; 

    }
}