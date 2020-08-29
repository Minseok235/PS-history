#include<iostream>
#include<algorithm>
#include <limits.h>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
int T,N,M; //T: num of test case, N: 문서의 수, M: 몇번째로 인쇄되는지 궁금한 문서가 현재 어디에 위치해있는지

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>T;
    for (int t=1; t<=T; t++){
        int cnt = 0;
        queue<pair<int,int>> q;
        priority_queue<int> pq;   //priority queue로 우선순위가 높은거 부터 
        cin>>N>>M;
        for (int i=0; i<N; i++){
            int a =0;
            cin>>a;
            q.push(make_pair(i, a));    // index,중요도 집어넣기
            pq.push(a);         //중요도 집얺기
        }
        while (!q.empty()){
            int cur_idx = q.front().first;
            int cur_importance = q.front().second;
            q.pop();
            if (pq.top() == cur_importance){
                pq.pop();
                cnt++;
                if (cur_idx == M){
                    cout<<cnt<<"\n";
                    break;
                }
            }
            else{
                q.push(make_pair(cur_idx, cur_importance));
            }

        }
    }


}
