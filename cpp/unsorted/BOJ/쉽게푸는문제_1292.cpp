// 1292_쉽게푸는문제
// 내가 푼 방식
/*#include <cstdio>
  int num[1002];

int main(){
  int s, e, sum = 0, idx = 0;
  for(int i = 1; i < 1001; i++){
    for(int j = i; j > 0 ; j--){
      if(idx > 1001) break;
      num[idx] = i;
      idx++;
    }
  }
  scanf("%d %d", &s, &e);

  for(int i = s-1; i < e; i++){
    sum += num[i];
  }
  printf("%d\n", sum);
  return 0;
}
*/
// AND 이렇게도 풀수있답!
#include <cstdio>
int main(){
  int s, e, limit = 1, count = 0, ans = 0;
  scanf("%d %d", &s, &e);
  for(int i = 1; i <= e; ++i, ++count){

    if(count >= limit){
      count = 0;
      limit++;
    }
    if(i >= s)
      printf("%d ", limit);
      
  }
  printf("%d\n", ans);
  return 0;
}

//OR 근데 런타임 에러 발생...
/*
#include <cstdio>
  int num[1002];

int main(){
  int s, e, sum = 0, idx = 0;
  scanf("%d %d", &s, &e);

  for(int i = 1; i <= e; i++){
    for(int j = i; j > 0; j--){
      num[idx] = i;
      idx++;
    }
  }
  for(int i = s-1; i < e; i++){
    sum += num[i];
  }
  printf("%d\n", sum);
  return 0;
}

*/
