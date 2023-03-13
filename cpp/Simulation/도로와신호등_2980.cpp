#include <cstdio>

int N, L;
int D[1001],R[101],G[101];

int main(){
  scanf("%d %d",&N, &L);
  for(int i = 0; i < N; i++)
    scanf("%d %d %d", &D[i], &R[i],&G[i]);

  int time = D[0];

  for(int i = 0; i < N; i++){
    if(i)
      time += D[i] - D[i-1];
    //빨간불
    int check = time % (R[i]+G[i]);
    if(check <= R[i])
      time += R[i] - check;
    else
      continue;
  }
  printf("%d\n", time+(L-D[N-1]));
  return 0;
}
