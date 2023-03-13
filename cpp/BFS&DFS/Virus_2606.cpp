#include <cstdio>
#include <vector>
using namespace std;
vector<int> com[101];
vector <bool> visited;
int cnt;

void dfs(int node){
  cnt++;
  visited[node] = true;

  for(int i = 0; i < com[node].size();i++){
    if(!visited[com[node][i]]){
      dfs(com[node][i]);
    }
  }
}

int main(){
  int N, M;
  scanf("%d", &N); scanf("%d", &M);

  for(int i = 0; i < M; i++){
    int a, b;
    scanf("%d %d", &a, &b);
    com[a].push_back(b);
    com[b].push_back(a);
  }
  visited = vector<bool> (N+1, false);
  cnt = 0;
  dfs(1);

  printf("%d\n", cnt-1);
  return 0;
}
