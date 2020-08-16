#include<iostream>
#include<algorithm>
#include <limits.h>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
int N,K;
int arr[105];
int a1,a2,b1,b2;
void input(){
    cin>>N>>K;
    for (int i=1; i<=N; i++){
        arr[i] = i;
    }
    cin>>a1>>a2;
    cin>>b1>>b2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    bool flag = true;
    int cnt = 0;
    for (int i=1; i<=K; i++){
        reverse(&arr[a1], &arr[a2+1]);
        reverse(&arr[b1], &arr[b2+1]);
        cnt++;
        flag = true;
        for (int i=1; i<=N; i++){
            if (arr[i]!=i) flag = false;
        }
        if (flag) break;
    }
    int cycle = K%cnt;
    for (int i=1; i<=cycle; i++){
        reverse(&arr[a1], &arr[a2+1]);
        reverse(&arr[b1], &arr[b2+1]);
    }
    for (int i=1; i<=N; i++){
        cout<<arr[i]<<"\n";
    }
}


//틀린이유: 처음에는 30번째줄에 flag를 초기화 시키지 않아 K가 매우 클 경우에는 시간 초과가 뜬다.(NK=10^11) 그리고 36번째 줄에 cycle=cnt%K 라 말도 안되는 실수를 했다. 디버깅 할때 한줄한줄 잘 읽자!
