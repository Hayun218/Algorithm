// 10026_dfs
#include <iostream>
#include <cstring>
using namespace std;

int N;
char map[101][101];
bool visited[101][101];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void dfs(int x, int y){
  visited[x][y] = 1;
  char &ret = map[x][y];
  for(int i = 0; i < 4; i++){
    int nx = x + dx[i];
    int ny = y + dy[i];
    if(nx >= 0 && ny >= 0 && nx < N && ny < N)
      if(ret == map[nx][ny] && !visited[nx][ny]) dfs(nx, ny);
  }
}

int solve(){
  int cnt = 0;
  memset(visited, false, sizeof(visited));
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(!visited[i][j]){
        cnt++;
        dfs(i,j);
      }
    }
  }
  return cnt;
}
int main(){
  cin >> N;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> map[i][j];
    }
  }
  int ans1 = solve();

  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
      if(map[i][j] == 'G')
        map[i][j] = 'R';
  int ans2 = solve();

  cout << ans1 << " " << ans2 << endl;
  return 0;
}
