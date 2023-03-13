//12.17 => 내일 다시 풀어보기 => done!
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string map[51]; // 스트링 타입으로!
int N;

int count(){
  int result = 1;

  // row check
  for(int i = 0; i < N; i++){
    int temp = 1;
    for(int j = 0; j < N -1; j++){
      if(map[i][j] == map[i][j+1])
        temp++;
      else{
        result = max(result, temp);
        temp = 1;
      }
    }
    result = max(result, temp);
  }

  // column check => 인덱싱 유의
  for(int i = 0; i < N; i++){
    int temp = 1;
    for(int j = 0; j < N-1; j++){
      if(map[j][i] == map[j+1][i])
        temp++;
      else{
        result = max(result, temp);
        temp = 1;
      }
    }
    result = max(result, temp);
  }
  return result;
}

int main(){
  cin >> N;
  for(int i = 0; i < N; i++)
    cin >> map[i];

  int ans = 1;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N -1; j++){
      // 좌우
      swap(map[i][j], map[i][j+1]);
      ans = max(ans, count());
      swap(map[i][j], map[i][j+1]); // 다시 원상복구
      // 상하
      swap(map[j][i], map[j+1][i]);
      ans = max(ans, count());
      swap(map[j][i], map[j+1][i]);
    }
  }
  cout << ans << endl;
  return 0;
}
