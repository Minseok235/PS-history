// BFS를 쓰는 문제, 다만 시작점이 하나로 정해져 있지 않고 여러곳에서 발생할 수 있으므로 처음에 queue에 1인 곳을 모두 찾아 넣어주면 각각 1에 대해서 BFS를 통해 답을 구할 수 있다.

#include<iostream>
#include<algorithm>
#include <limits.h>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
int M,N,day;        //M->가로, N->세
int map[1005][1005], dist[1005][1005];        // 1->익은 토마토, 0-> 안익은, -1 -> 비어있음
bool visited[1005][1005];
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

void input(){
    cin>>M>>N;
    for (int i=1; i<=N; i++){
        for (int j=1; j<=M; j++){
            cin>> map[i][j];
        }
    }
}

void BFS(){
    queue<pair<int,int>> q;
    for (int i=1; i<=N; i++){
        for (int j=1; j<=M; j++){
            if (map[i][j]==1){
                q.push(make_pair(i,j));
            }
        }
    }
    while (!q.empty()){
        int cur_r = q.front().first;
        int cur_c = q.front().second;
        q.pop();
        visited[cur_r][cur_c] = true;
        for (int i=0; i<4; i++){
            int new_r = cur_r + dir[i][0];
            int new_c = cur_c + dir[i][1];
            if (new_r>=1&& new_c>=1 && new_r<=N && new_c<=M && !visited[new_r][new_c] && map[new_r][new_c]==0){
                visited[new_r][new_c] = true;
                map[new_r][new_c] = map[cur_r][cur_c]+1;
                q.push(make_pair(new_r,new_c));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    BFS();
    int ans = -1;
    bool Allripe = true;
    for (int i=1; i<=N; i++){
        for (int j=1; j<=M; j++){
            if (map[i][j]==0){
                Allripe = false;
            }
            if (map[i][j]>ans){
                ans = map[i][j];
            }
        }
    }
    if (Allripe) cout<<ans-1;
    else{
        cout<<-1;
    }

}


