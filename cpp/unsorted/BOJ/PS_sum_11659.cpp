#include <cstdio>

int main()
{
    int n, m, psum[100001];
    scanf("%d %d", &n, &m);
    for(int i = 1 ; i < n+1; i++){
        scanf("%d", psum+i);
        psum[i] += psum[i-1]; 
    }
    for(int i = 0; i < m; i++){
        int s, e;
        scanf("%d %d", &s, &e);
        printf("%d\n", psum[e] - psum[s-1]);
    }
}