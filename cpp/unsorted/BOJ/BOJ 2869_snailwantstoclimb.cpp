#include <cstdio>

int A, B, V;

int main(){
  scanf("%d %d %d", &A,&B,&V);

  int day = ((V-B-1)/(A-B)) + 1;
  /*
  A-B 만큼 하루에 올라간다
  맨 마지막 정상지점에서는 미끄러지지 않으니 V-B만큼에만 도달하면 된다
  나누어 떨어지지 않을 경우 +1을 해야하므로 -1을 해주고 몫에다가 +1을 한다
  아이디어 출처: https://yahohococo.tistory.com/28

  결국 수학문제.. 사고방식..
  */

  printf("%d\n", day);
  return 0;
}
