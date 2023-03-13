// tree_Tree_13244

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

vector<int> tree[1001];
int T, N, M;
bool visited[1001];

void dfs(int cur){
  visited[cur] = true;
  for(int next : tree[cur])
    if(!visited[next]) dfs(next);
  return;
}

int main(){
  cin >> T;
  while(T--){
    memset(visited, false, sizeof(visited));
    cin >> N; cin >> M;
    for(int i = 0; i < M; i++){
      int u, v;
      cin >> u >> v;
      tree[u].push_back(v);
      tree[v].push_back(u);
    }
    int cnt = 0;
    for(int i = 1; i <= N; i++){
      if(!visited[i]) {
        dfs(i);
        cnt++;
    }
  }
  if(N-1==M && cnt == 1) cout << "tree";  // tree일 경우 component가 한개이므로 dfs로 탐색하였을 때 한번에 모든 노드를 방문 
  else cout <<"graph";
  cout << "\n";
  }
  return 0;
}
