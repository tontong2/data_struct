#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)

// n명씩 같은 칸에 모이도록 움직여야 하는 최소 거리 수 
// 입력은 50보다 작거나 같다.
// x는 1,000,000보다 작거나 같다.

// 4
// 15 14
// 15 16
// 14 15
// 16 15

#define INF 1e9
#define MX 51

int answer[MX]; 
int x[MX];
int y[MX];


int main(void){
    fastio;

    int n;
    cin >> n;
    
    // 최솟값을 구하기 위해 큰 값으로 초기화
    fill(answer, answer + MX, INF);

    // 좌표 저장
    for(int i=0; i<n; i++){
        cin >> x[i] >> y[i];
    }

    // 각 지정된 좌표와 체커들의 거리를 저장 
    int dist[MX];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int target_x = x[i];
            int target_y = y[j];

            for(int k=0; k<n; k++){
                dist[k] = abs(x[k] - target_x) + abs(y[k] - target_y);
            }
            
            sort(dist, dist+n);
            // 각 구한 거리를 정렬을 하면 적은순으로 나오고 그것은 곧 몇개의 체커를 모을지에 대한 답이됨.

            int sum = 0;
            for(int k=0; k<n; k++){
                sum += dist[k];
                answer[k] = min(answer[k], sum);
            }
        }
    }
    for(int i=0; i<n; i++){
        cout << answer[i] << " ";
    }
}
