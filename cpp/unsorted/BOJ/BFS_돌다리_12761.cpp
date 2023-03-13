// BFS_돌다리_12761

#include <iostream>
#include <queue>
using namespace std;

bool visited[100001];
queue <int> q;

int main(){
  int N, M, A, B, pos, qz = 0, ans = 0;
  cin >> A >> B >> N >> M;

  int jump[8] = {1, -1, A, -A, B, -B, A, B};

  visited[N] = 1;
  q.push(N);
  while(!q.empty()){
    qz = q.size();
    while(qz--){
      pos = q.front();
      q.pop();
      if(pos == M){
        cout << ans << "\n";
        break;
      }
      int next;
      for(int i = 0; i < 8; i++){
        if(i >= 6) next = pos * jump[i];
        else next = pos + jump[i];
        if(next > 100000 || next < 0) continue;
        if(visited[next]) continue;
        visited[next] = 1;
        q.push(next);
      }
    } ans++;
  }
}
