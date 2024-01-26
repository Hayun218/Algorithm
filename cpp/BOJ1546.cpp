#include <cstdio>

int main() {
    int N;
    double ans = 0.0;
    int n[1000], max = 0.0;

    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        scanf("%d", &n[i]);
        if(n[i] > max) max = n[i];
    }

    for(int i = 0; i < N; i++) 
        ans = ans + (double)n[i] / (double)max * 100;

    ans = ans / N;
    printf("%f\n", ans);

    return 0;
}