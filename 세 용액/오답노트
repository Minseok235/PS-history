#include<iostream>
#include<algorithm>
#include <limits.h>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
int N;
long long int arr[5005];
void input(){
    cin>>N;
    for (int i=1; i<=N; i++){
        cin>>arr[i];
    }
    sort(&arr[1], &arr[N+1]);
}
//sort=>[-97 -6 -2 6 98]
long long int BS(int idx1, int idx2){      //sort된 arr에서 -x와 합이 0에 가장 가까운 element 찾고 싶음 -x가 sorted된 arr에서 갖는 위치(인덱스)
    int L=idx2+1, R=N,p;
    int x = arr[idx1]+arr[idx2];
    int loc = 0;
    while (L<=R){
        int mid = (L+R)/2;
        if (arr[mid]+x==0) return arr[mid];
        else if (arr[mid]>-x){
            R=mid-1;

        }
        else{
            L=mid+1;
            loc = mid;
        }
    }
    if (loc == N) p = arr[N];
    else if (loc == 0) p =arr[idx2+1];
    else{
        if (arr[loc+1]+x<-x-arr[loc]) p = arr[loc+1];
        else p = arr[loc];
    }
    return p;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    if (N==3){
        cout<<arr[1]<<" "<<arr[2]<<" "<<arr[3];
        exit(0);
    }
    // -3 -2 3 6
    long long int minimum = LLONG_MAX;
    int x1, x2, x3;
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N-1; j++) {
            long long int target = arr[i] + arr[j];
            long long int pair = BS(i, j);    //index가 겹치지 않으려면 항상 j보다 큰 인덱스에서 찾아 봐야함
            if (target + pair == 0) {
                cout << arr[i] << " " << arr[j] << " " << pair;
                exit(0);
            }
            if (abs(target + pair) < minimum) {
                minimum = abs(target + pair);
                x1 = arr[i];
                x2 = arr[j];
                x3 = pair;
            }
        }
    }
    cout << x1 << " " << x2 << " " << x3;
}

// 틀린 이유: BS함수에서 이분탐색을 할 때 오른쪽 끝의 범위의 초기값을 계속 N-1로 했다. 내가 arr이라는 어레이에 0부터가 아니라 1부터 채워넣었다는것을 명심해야함.
