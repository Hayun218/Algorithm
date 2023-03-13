#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

const int INF = -987654321;

int main(){
  int N;
  scanf("%d", &N);

  int A[N+1];
  vector<int> arr(N+1);
  typedef pair <int, int> P;
  vector<P> trace(N+1);
  stack<int> s;

  for(int i = 0; i < N; i++)
    scanf("%d", A+i);

  arr.push_back(INF);
  int ans = 0;

  for(int i = 0; i < N; i++){
    if(A[i] > arr.back()){
      arr.push_back(A[i]);
      trace.push_back({i, A[i]});
      ans++;
    }
    else {
      auto it = lower_bound(arr.begin(), arr.end(), A[i]);
      *it = A[i];
      trace.push_back({*it, A[i]});
    }
  }
  printf("%d\n", ans);

  for(int i = N-1; i >= 0; i--){
    if(trace[i].first == ans){
      s.push(trace[i].second);
      ans--;
    }
  }
  while(!s.empty()){
    printf("%d ", s.top());
    s.pop();
  }
  return 0;
}
