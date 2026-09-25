#include <iostream>
#include <queue>

using namespace std;

// 토마토의 좌표값
struct coordinate {
  int x;
  int y;
  int z;
};

int M, N, H, tomato; 
int box[101][101][101];
int visited[101][101][101];
queue<coordinate> Q;

int day = 0;

int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

int bfs() {
  while(!Q.empty()){
    int now_x = Q.front().x;
    int now_y = Q.front().y;
    int now_z = Q.front().z;
    Q.pop();

    for(int i=0; i<6; i++){
      int nx = now_x + dx[i];
      int ny = now_y + dy[i];
      int nz = now_z + dz[i];

      if(nx <0 || nx >= M || ny <0 || ny >= N || nz < 0 || nz >= H)continue;
      if(box[nz][ny][nx] == 0 && visited[nz][ny][nx] == -1) {
        coordinate add_tomato;
        box[nz][ny][nx] = 1;
        add_tomato.x = nx;
        add_tomato.y = ny;
        add_tomato.z = nz;
        Q.push(add_tomato);
        visited[nz][ny][nx] = visited[now_z][now_y][now_x] + 1;
      }
    }
  }
  for(int h=0; h<H; h++){
    for(int n=0; n<N; n++){
      for(int m=0; m<M; m++){
        if(box[h][n][m] == 0) return -1;
        day = max(day, visited[h][n][m]);
      }

    }
  }

  return day;
}

int main(void){
  cin >> M >> N >> H;
  fill_n(&box[0][0][0], 101*101*101, -1);

  for(int h=0; h<H; h++){
    for(int n=0; n<N; n++){
      for(int m=0; m<M; m++){
        cin >> tomato;
        box[h][n][m] = tomato;

        coordinate tomato_coord;
        tomato_coord.x = m;
        tomato_coord.y = n;
        tomato_coord.z = h;

        if(tomato == 1){
          Q.push(tomato_coord);
        }
        if(tomato == 0){
          visited[h][n][m] = -1;
        }
      }

    }
  }

  cout << bfs();
  return 0;

}