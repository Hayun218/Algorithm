#include <cstdio>
int main(){
  int R, B;

  scanf("%d %d", &R, &B);

  int w, l;

  for(l = 1; ;l++){
    if(B % l == 0)  // to balance out
      w = B/l;

    if((w+2) * (l+2) == R+B){ // *important in finding rules => 10+2 = 4*3
      printf("%d %d\n", w+2, l+2);
      break;
    }
  }
  return 0;


}
