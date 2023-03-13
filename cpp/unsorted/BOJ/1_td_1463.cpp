#include <cstdio>

int solve(int n)
{
    if(n <= 1) return 0;
    int res1 = solve(n/3) + n%3 + 1;
    int res2 = solve(n/2) + n%2 + 1;
    return res1 < res2 ? res1 : res2;
}

int main()
{
    int N;
    scanf("%d", &N);
    printf("%d", solve(N));
}