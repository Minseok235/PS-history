// BFS를 이용해 시작점(처음 값)에서 x-1, x+1, 2*x 중 하나로 이동해 특정숫자가 되기 까지 최단시간을 구할 수 있다. 처음에 계속 런타임 에러가 떴는데 36번 줄 if문에서 범위를 체크하는 조건보다
// visited가 false인지 체크하는 조건을 먼저 써서 new_x값이 음수일 때 visited 배열에 인덱스에 음수 값을 넣어서 일어난 것이였다. 

#include<iostream>
#include<algorithm>
#include <limits.h>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
int N,K;    // int 범위
bool visited[100005];   // 0부터 100000까지니까 넉넉 잡고 100005
int dist[100005];       // 정답의 범위는 int 범위
int dir[5]{1,-1,0};

void input(){
    cin>>N>>K;      //현재 나의 위치 N, 동생의 위치 K
}

void BFS(int start){        // 시작점부터 x-1, x+1, 2*x중 하나로 이동해 한 숫자에 도착하기까지 최단시간을 구한
    queue<int> q;
    q.push(start);
    visited[start] = true;
    dist[start] = 0;
    while (!q.empty()){
        int x = q.front();
        q.pop();
        for (int i=0; i<3; i++){
            int new_x = 0;
            if (dir[i]!=0){
                new_x = x + dir[i];
            }
            else {
                new_x = 2*x;
            }
            if (new_x>=0 && new_x<=100000 && !visited[new_x]){
                dist[new_x] = dist[x]+1;
                visited[new_x] = true;
                q.push(new_x);
            }

            if (new_x == K){        // K를 찾는 즉시 그때의 dist 값 프린트
                cout<<dist[new_x];
                exit(0);
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    BFS(N);     //시작 위치 N

}



