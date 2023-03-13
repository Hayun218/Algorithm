#include <cstdio>

int main(){
  int N, M, A[10001];
  int s = 0, e = 0, cnt = 0, sum = 0;

  scanf("%d %d", &N, &M);
  for(int i = 0; i < N; i++)
    scanf("%d", A+i);

  while(1){
    if(sum >= M) sum -= A[s++];
    else if(e == N) break;
    else sum += A[e++];
    if(sum == M) cnt++;
  }
  printf("%d\n", cnt);
  return 0;
}
