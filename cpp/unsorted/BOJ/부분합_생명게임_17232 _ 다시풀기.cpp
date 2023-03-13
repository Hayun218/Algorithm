// 부분합_생명게임_17232 _ 다시풀기

#include <cstdio>
#include <algorithm>
using namespace std;

const int max_N = 101;

int N, M, T, K, a, b;
char map[max_N][max_N];
int dp[max_N][max_N], life;

int main(){
  scanf("%d %d %d", &N, &M, &T);
  scanf("%d %d %d", &K, &a, &b);

  for(int i = 1; i <= N; i++)
    for(int j = 1; j <= M; j++)
      scanf("%c", &map[i][j]);

  while(T--){
    for(int i = 1; i <= N; i++){
      for(int j = 1; j <= M; j++){
        if(map[i][j] == '*')  dp[i][j] = dp[i+1][j] + dp[i][j+1] - dp[i-1][j-1] + 1;
        else  dp[i][j] = dp[i+1][j] + dp[i][j+1] - dp[i-1][j-1];
      }
    }
    for(int i = 1; i <= N; i++){
      for(int j = 1; j <= M; j++){
        int up = max(i+K, 0), down = min(N, i-K-1), right = min(M, i+K-1), left = max(0, i - K-1);
        if(map[i][j] == '*') life = dp[down][right] - dp[down][left] - dp[up][right] + dp[up][left] - 1;
        else life = dp[down][right] - dp[down][left] - dp[up][right] + dp[up][left];

        if(map[i][j] == '*') {
          if(life < a || life > b) map[i][j] = '.';
        } else {
          if(life > a && life <= b) map[i][j] = '*';
        }
      }
  }


  }
  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= M; j++)
      printf("%c", map[i][j]);
    printf("\n");
  }
  return 0;
}
