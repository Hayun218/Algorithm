// 시간초과나는 경우 O(N^2)
#include <cstdio>
const int Max_N = 100000;

int formula(int x1, int x2, int y1, int y2){
    return (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1);
}

int main()
{
    int N, x[Max_N], y[Max_N];
    int ans = -1;
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d %d", x+i, y+i);

    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N-1; j++){
            int d = formula(x[j], x[i], y[j], y[i]);
            if(ans == -1 || d < ans)
                ans = d;
        }
    }
    printf("%d\n", ans);
    return 0;
}