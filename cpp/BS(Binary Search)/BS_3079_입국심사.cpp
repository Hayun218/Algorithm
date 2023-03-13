/*
- 문제핵심:
  -  답을 미리 선정해서 그 값을 이분탐색으로 확인한다는 접근방식!!

- 어려웠던점:
  - 이분탐색이라는 건 힌트를 통해 먼저 보게 되었는데 도대체 어떻게 이분탐색이 진행되는 지 몰랐었다.
*/

#include <cstdio>
typedef long long ll;

int N, M;
ll counter[100001];
ll result, max = 0;

int main(){
  scanf("%d %d", &N, &M);
  for(int i = 0; i < N; i++){
    scanf("%lld", &counter[i]);
    if(counter[i] > max)
      max = counter[i];
  }
  ll right = max *M;
  ll left = 1;

  while(left <= right){
    ll mid = (right+left)/2;
    result = mid+1;
    ll total = 0;
    for(int i = 0; i < N; i++){
      total += mid/counter[i];
    }
    if(total < M){
      left = mid + 1;
    }else{
      right = mid - 1;
    }
  }

  printf("%lld\n", result);
  return 0;
}
