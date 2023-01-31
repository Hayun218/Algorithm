#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int N, M, K;
  cin >> N >> M >> K;
  int numbers[N+1];
  int ans = 0;

  for(int i = 0; i < N; i++){
    cin >> numbers[i];

  }

  sort(numbers, numbers+N);

  for(int i = 0; i < M; i++){
    if((i+1) % K == 0){
      ans += numbers[N-2];
    }else{
      ans += numbers[N-1];
    }
  }

  cout << ans << endl;
}
