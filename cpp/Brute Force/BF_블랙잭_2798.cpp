#include <cstdio>
const int max_N = 101;

int main(){
  int N, M, card[max_N];
  scanf("%d %d", &N, &M);

  for(int i = 0; i < N; i++)
    scanf("%d", card+i);

  int max = 0, sum = 0;
  for(int i = 0; i < N; i++)
    for(int j = i+1; j < N; j++)
      for(int k = j+1; k < N; k++){
        sum = card[i] + card[j] + card[k];
        if(sum <= M && max < sum) max = sum;
      }

  printf("%d", max);
  return 0;
}
