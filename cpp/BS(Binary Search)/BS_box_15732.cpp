#include <cstdio>
#include <algorithm>
#define max 10000
using namespace std;

int main(){
    int n, k, d, a[max], b[max], c[max];
    scanf("%d %d %d", &n, &k, &d);
    for(int i = 0; i < k; i++){
        scanf("%d %d %d", a+i, b+i, c+i);
    }
    int cnt, low, high, mid;
    low = 0;
    high = n;
    while(low+1 < high){
        mid = (low + high) / 2;
        cnt = 0;
        for(int i = 0; i < k; i++){
            int temp = min(b[i], mid);
            if(temp >= a[i])
                cnt += (temp - a[i]) / c[i] + 1;
        }
        (cnt >= d ? high : low) = mid;
    }
    printf("%d", high);
    return 0;
}