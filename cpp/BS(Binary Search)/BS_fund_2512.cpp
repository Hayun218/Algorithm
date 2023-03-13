#include <cstdio>

int main()
{
    int N, M, data[10002];
    int ans, temp;
    int high = 1, low = 0;

    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", data+i);
        high = high < data[i] ? data[i] : high;
    }
    scanf("%d", &M);

    while(high >= low){
        temp = 0;
        int mid = (high + low) / 2;
        
        for(int i = 0; i < N; i++)
            temp += mid > data[i] ? data[i] : mid;// ㅠㅠ
        if(M >= temp){
            low = mid + 1;
            ans = mid;
        }
        else high = mid - 1;
    }
    printf("%d\n", ans);
    return 0;
}
/*#include<cstdio>
#include<algorithm>
int n, t, m, i, a[10000];
int main() {
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", a + i);
    std::sort(a, a + n);
    scanf("%d", &m);
    for (i = 0; t + a[i] * (n - i) < m && i < n; i++) t += a[i];
    printf("%d", i == n ? a[n - 1] : (m - t) / (n - i));
    return 0;
}*/