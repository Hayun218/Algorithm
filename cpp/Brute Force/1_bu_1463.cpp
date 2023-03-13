#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N = 1000001;

int main()
{
    int N, dp[MAX_N];
    scanf("%d", &N);

    fill(dp, dp+MAX_N, 1000000000);
    dp[1] = 0;
    for(int i = 1; i < N; i++){
        dp[i+1] = min(dp[i + 1], dp[i] + 1);
        if(N * 2 < MAX_N) dp[2*i] = min(dp[2*i], dp[i] + 1);
        if(N * 3 < MAX_N) dp[3*i] = min(dp[3*i], dp[i] + 1);
    }  
    printf("%d\n", dp[N]);
    return 0;
}