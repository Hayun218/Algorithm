#include <cstdio>

int main() {
    char word[1000001];
    int cnt[26];
    int max = 0;
    char maxC;

    scanf("%s", word);    

    for (int i = 0; word[i]; i++) {
          // 대문자로 변환
        if (word[i] >= 'a' && word[i] <= 'z') word[i] -= 32;
        
        for (char n = 'A'; n <= 'Z'; n++) {
            if (word[i] == n) {
                cnt[n-65]++;
                if (cnt[n-65] > max) {
                    max = cnt[n-65];
                    maxC = n;
                } else if (cnt[n-65] == max) {
                    maxC = '?';
                }
            }
        }
    }

    printf("%c\n", maxC);

    return 0;
}