#include <cstdio>

int N, S, cnt, num[30];

void dfs(int i, int sum){
    if(sum + num[i] == S) cnt++;
    if(i == N-1) return;

    dfs(i+1, sum);
    dfs(i+1, sum+num[i]);
}

int main(){
    scanf("%d %d", &N, &S);
    for(int i = 0; i < N; i++)
        scanf("%d", &num[i]);
    dfs(0, 0);
    printf("%d\n", cnt);
}
