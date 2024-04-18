#include <cstdio>

int factorial(int a) {
    if(a == 1 || a == 0) return 1;
    return a * factorial(a-1); 
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    printf("%d\n", factorial(n)/(factorial(k)*factorial(n-k)));

    return 0;
}