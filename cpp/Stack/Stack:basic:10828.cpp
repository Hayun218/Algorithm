#include <iostream>
using namespace std;

int main(){
  int N;
  string com;
  Stack<int> S;
  scanf("%d", &N);
  for(int i = 0; i < N; i++){
    scanf("%s", com);
    switch(com){
      case push:
        int num;
        scanf("%d", &num);
        S.push(num);
        break;
      case pop:
        if(!S.empty){
          printf("%d", S.top());
          S.pop();
        }
        printf("-1\n");
        break;
      case size:
        printf("%d\n", S.size());
        break;
      case empty:
        if(S.empty())
          printf("1\n");
        printf("0\n");
      case top:
        if(!S.empty())
          printf("%d\n", S.top());
        printf("-1\n");
        break;
    }
  }
  return 0;
}
