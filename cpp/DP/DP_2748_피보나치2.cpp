#include <iostream>
using namespace std;
long long dp[91]; // int의 범위를 벗어나서 long long으로 하여야함
int N;

int main(){
  cin >> N;
  dp[0] = 0; dp[1] = 1;

  for(int i = 2; i <= N; i++)
    dp[i] = dp[i-1]+dp[i-2];

  cout << dp[N] << endl;
  return 0;
}
