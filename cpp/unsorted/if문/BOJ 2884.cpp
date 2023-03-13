// 45분 일찍 알람 맞추기

#include <iostream>
using namespace std;

int main(){
  int H, M;
  cin >> H >> M;

  if(M - 45 < 0){
    M += 15;
    if(H - 1 < 0)
      H = 23;
    else H--;
  } else{
    M -= 45;
  }
  cout << H << " " << M;
  return 0;
}
