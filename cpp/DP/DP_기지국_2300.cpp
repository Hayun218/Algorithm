// DP_기지국_2300

#include <cstdio>
#include <algorithm>
using namespace std;

int dp[10001];
pair <int, int> pos[10001];

int main(){
  int N;
  scanf("%d", &N);
  for(int i = 1; i <= N; i++)
    scanf("%d %d", &pos[i].first, &pos[i].second);

  sort(pos+1, pos+N+1);

  for(int i = 1; i <= N; i++){
    int lx = pos[i].first;
    int rx = pos[i].first;
    int y = abs(pos[i].second);
    dp[i] = 0x3f3f3f3f;
    for(int j = i-1; j >= 0; j--){
      int w = max(abs(rx - lx), 2*y);
      dp[i] = min(dp[i], dp[j]+w);
      lx = pos[j].first;
      y = max(y, abs(pos[j].second));
    }
  }
  printf("%d\n", dp[N]);
  return 0;
}
