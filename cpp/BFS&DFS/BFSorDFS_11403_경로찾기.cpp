//dfs로 구현
#include <cstdio>
#include <cstring>
using namespace std;

int G[101][101];
int N;
int visited[101];

void dfs(int node){
  for(int i = 0; i < N; i++){
    if(G[node][i] && !visited[i]){
      visited[i] = 1;
      dfs(i);
    }
  }
}

int main(){
  scanf("%d",&N);
  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
      scanf("%d", &G[i][j]);

  for(int i = 0; i < N; i++){
    memset(visited, 0, sizeof(visited));
    dfs(i);

    for(int j = 0; j < N; j++){
      if(visited[j])
        G[i][j] = 1;
    }
  }
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      printf("%d ",G[i][j]);
    }
    printf("\n");
  }

  return 0;
}
