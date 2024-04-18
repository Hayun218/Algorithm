#include <cstdio>

int main() {
    int N, n[100] = {0, }, cnt = 0;
    scanf("%d", &N);
    
    for(int i = 0; i < N; i++) {
        int j;
        scanf("%d", n+i);
        if(n[i] == 1) continue;

        for(j = 2; j < n[i]; j++) {
            if (n[i] % j == 0) break;
        }
        if (j == n[i]) cnt++;
    }
    
    printf("%d\n", cnt);

    return 0;
}