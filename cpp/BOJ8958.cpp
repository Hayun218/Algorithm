#include <cstdio>

int main() {
    int N;
    scanf("%d", &N);

    while(N--) {
        char score[81];
        int cnt = 0, ans = 0;

        scanf("%s", score);

        for(int i = 0; score[i]; i++) 
            score[i] == 'O' ? ans += ++cnt : cnt = 0;
        
        printf("%d\n", ans);
    }
    return 0;
}