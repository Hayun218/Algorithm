// 틀렸습니다...?
#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 1000000000;

int main(){
  int n, m, dist[101][101];
  scanf("%d %d", &n, &m);

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      dist[i][j] = i==j ? 0 : INF;

  for(int i = 0; i < m; i++){
    int a, b, c;
    scanf("%d %d %d",&a, &b, &c);
    dist[a-1][b-1] = min(dist[a-1][b-1], c);
  }

  for(int k = 0; k < n; k++)
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++)
      printf("%d ", dist[i][j]);
    printf("\n");
  }
  return 0;
}
