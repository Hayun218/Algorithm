#include <cstdio>

int main() {
    int N;
    while(true) {
        scanf("%d", &N);
        if(!N) return 0;

        int M = N, q = 0;

        while(N) {
            q = q * 10 + N % 10;
            N /= 10;
        }
        if(q == M) printf("yes\n");
        else printf("no\n");
    }
}