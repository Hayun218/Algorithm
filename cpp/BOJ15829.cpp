#include <cstdio>

int main() {
    int N; 
    long long r = 1, ans = 0;
    long long M = 1234567891;
    char letters[50];

    scanf("%d\n", &N);

    for(int i = 0; i < N; i++) {
        scanf("%c", &letters[i]);
        r = 1;

        for(int j = 1; j <= i; j++) {
            r *= 31;
            if (r > M) r = r % M;
        }

        ans += (char(letters[i]) - ('a'-1)) * r;
    }
    if (ans > M) ans = ans % M;
    printf("%lld\n", ans);
    
    return 0;
}