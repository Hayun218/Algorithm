#include<cstdio>

int main() {
    int T;
    scanf("%d", &T);

    while(T--) {
        int H, W, N;

        scanf("%d %d %d", &H, &W, &N);
        if (N % H == 0) printf("%d\n", H * 100 + (N / H));
        else printf("%d\n", N % H * 100 + (N / H + 1));
        //  printf("%d%02d\n", (N-1) % H + 1, (N-1) / H + 1);
    }
    return 0;
}