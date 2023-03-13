#include <iostream>
using namespace std;

const int divN = 1000000003;
int N, K;
int dp[1001][1001];

void cal(){
  for(int i = 1; i < 4; i++)
    dp[i][1] = i; //  N (4 ≤ N ≤ 1,000) 이기에 N이 4 이하의 경우를 미리 define

  for(int i = 4; i <= N; i++){
    int maxC = i/2;
    for(int j = 1; j <= maxC; j++){ // j = 선택하는 색의 갯수
      if(j == 1) dp[i][1] = i;
      else
        dp[i][j] = (dp[i-2][j-1] + dp[i-1][j]) % divN; // 선택했을 경우와 안했을 경우
    }
  }

}
int main(){
  cin >> N >> K;

  cal();
  cout << dp[N][K] << endl;
  return 0;
}
