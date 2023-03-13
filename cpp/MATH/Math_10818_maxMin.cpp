#include <cstdio>
using namespace std;

int main(){
  int N = 0;
  scanf("%d", &N);
  int min = 1000001, max = -1000001;
  int num = 0;
  for(int i = 0; i < N; i++){
    scanf("%d", &num);
    if (num > max)
      max = num;
      if (num < min)
      min = num;
  }

  printf("%d %d\n", min, max);
  return 0;
}
