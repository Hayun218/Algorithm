#include <cstdio>

 // 유클리드 호제법
int gcd(int a, int b) {
    int c = a % b;

     while(c != 0) {
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}

int lcm(int a, int b) {
    // 수학공식: gcd * lcm = a * b 
    return (a * b) / gcd(a,b);
}

int main() {
    int a, b;

    scanf("%d %d", &a, &b);

    if(b > a) {
        int temp = a;
        a = b;
        b = temp;
    }

    printf("%d\n%d\n", gcd(a,b), lcm(a,b));

    return 0;
}