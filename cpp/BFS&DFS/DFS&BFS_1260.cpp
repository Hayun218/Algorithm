#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector <int> graph[1001];
vector <bool> visited;
queue <int> q;
int N, M, V;

void dfs(int node){
  printf("%d ", node);
  for(int i = 0; i < graph[node].size();i++){
    if(!visited[graph[node][i]]){
      visited[graph[node][i]] = true;
      dfs(graph[node][i]);
    }
  }
}

void bfs(){
  q.push(V);
  visited[V]= true;
  while(!q.empty()){
    int node = q.front();
    q.pop();
    printf("%d ", node);

    for(int i = 0; i < graph[node].size(); i++){
      if(!visited[graph[node][i]]){
        visited[graph[node][i]] = true;
        q.push(graph[node][i]);
      }
    }
  }
}

int main(){
  scanf("%d %d %d", &N, &M, &V);
  for(int i = 0; i < M; i++){
    int a, b;
    scanf("%d %d", &a, &b);
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  for(int i = 0; i < N; i++)
    sort(graph[i].begin(), graph[i].end());

  visited = vector<bool>(N+1, false);
  visited[V] = true;
  dfs(V);
  printf("\n");
  visited = vector<bool>(N+1, false);
  bfs();

  return 0;
}
/*
visited[node]= true를 dfs 첫 줄에 적으면 아무이상없는데도 백준에서는 컴파일 에러 발생! 와이..?
*/
