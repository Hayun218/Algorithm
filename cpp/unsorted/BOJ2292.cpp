#include <cstdio>

int main() {
    int N, sum = 2, i = 1;
    scanf("%d", &N);

    for(i = 1; sum <= N; i++) sum += 6*i;
     if(N == 1) i = 1;

    printf("%d\n", i);
    return 0;
}