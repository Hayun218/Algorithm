#include <cstdio>

int main(){
  int con;
  scanf("%d", &con);
  int n = 1;
  int ans = n;

  while(1){
    int temp = n;
    while(temp){
      ans += temp%10;
      temp /= 10;}
    if(n == con){
      printf("0\n");
      break;
    }else if(ans == con){
      printf("%d\n", n);
      break;
    } else {
      n++;
      ans = n;
    }
  }
  return 0;
}
