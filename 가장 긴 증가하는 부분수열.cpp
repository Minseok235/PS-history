#include<iostream>
#include<algorithm>
#include <limits.h>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
int N;
int D[1005], A[1005];           // D[i] => i번째 원소를 마지막으로 갖는 증가부분 수열의 가장 긴 길이
void input(){
    cin>>N;
    for (int i=1; i<=N; i++){
        cin>>A[i];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    int ans = 0;
    for (int i=1; i<=N; i++){
        int maximum = 0;
        for (int j=1; j<=i-1; j++){
            if (A[i]>A[j]){
                if (maximum<D[j]){
                    maximum = D[j];
                }
            }
        }
        D[i] = maximum+1;
        ans = max(D[i], ans);
    }
    cout<<ans;
}
//틀린이유: 의미에 맞게 variable 이름을 정하는 습관을 들이자. 이 경우에서는 maximum이 가장 긴 길이를 의미 하므로 최대값과 관련이 있다. 31번째 줄에 D[i]=maximum+1인데 +1을 한 이유는 자기 자신도 세야하기 떄문.


