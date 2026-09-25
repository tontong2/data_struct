#include <iostream>
#include <util.h>
using namespace std;

#define X first
#define Y second

int board[502][502] =
{
    {1, 1, 0, 1, 1},
    {0, 1, 1, 0, 0},
    {0, 0, 0, 0, 0},
    {1, 0, 1, 1, 1},
    {0, 0, 1, 1, 1},
    {0, 0, 1, 1, 1}
};

bool vis[502][502];
int n = 6, m = 5; 
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int mx = 0; // 그림의 최대값
    int num = 0; // 그림의 수 

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j] == 0 || vis[i][j]) continue;
            num++;
            queue<pair<int,int> > Q;
            vis[i][j] = 1; // 해당 위치를 방문했다고 명시
            Q.push({i, j}); // 큐에 시작점인 해당 좌표를 삽입.
            int area = 0;
        
            while(!Q.empty()){
                area++;
                pair<int, int> cur = Q.front(); Q.pop();
                for(int dir=0; dir<4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= n || ny<0 || ny >= m) continue;
                    if(vis[nx][ny] || board[nx][ny] != 1) continue;
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
            mx = max(mx, area);
        }
    }
    cout << num << "\n" <<  mx;
}