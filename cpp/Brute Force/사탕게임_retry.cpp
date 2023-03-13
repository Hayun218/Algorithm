// 맞춤! 12.18
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string candy[51];
int N;

int solve(){
  int cnt = 1;
  int ans = 0;
  for(int i = 0; i < N; i++){
    cnt = 1;
    for(int j = 0; j < N-1; j++){
      if(candy[i][j] == candy[i][j+1])
        cnt++;
      else{
        ans = max(ans, cnt);
        cnt = 1;
      }
    }
    ans = max(ans, cnt);
  }

  for(int j = 0; j < N; j++){
    cnt = 1;
    for(int i = 0; i < N-1; i++){
      if(candy[i][j] == candy[i+1][j])
          cnt++;
        else{
          ans = max(ans, cnt);
          cnt = 1;
        }
      }
      ans = max(ans, cnt);
    }
    return ans;
}

int main(){
  cin >> N;
  for(int i = 0; i < N; i++)
    cin >> candy[i];

  int result = 0;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N-1; j++){
      swap(candy[i][j], candy[i][j+1]); // 좌우
      result = max(result, solve());
      swap(candy[i][j], candy[i][j+1]);

      swap(candy[j][i], candy[j+1][i]); // 상하
      result = max(result, solve());
      swap(candy[j][i], candy[j+1][i]);
    }
  }

  cout << result << endl;
  return 0;
}
