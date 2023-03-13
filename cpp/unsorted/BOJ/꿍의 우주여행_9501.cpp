#include <iostream>
using namespace std;
int N, D;

int main(){
  int T;
  cin >> T;
  while(T--){
    int cnt = 0;
    cin >> N >> D;

    for(int i = 0; i < N; i++){
      int v,f,c;
      cin >> v >> f >> c;
      float div = (float)D/(float)v;
      if(div * (float)c <= f)
        cnt++;
    }
    printf("%d\n",cnt);
  }
  return 0;
}
