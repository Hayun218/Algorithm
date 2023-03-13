// 시험성적
// 90 ~ 100점은 A, 80 ~ 89점은 B, 70 ~ 79점은 C, 60 ~ 69점은 D, 나머지 점수는 F
#include <iostream>
using namespace std;

int main(){
  int score;
  cin >> score;
  if(90 <= score && score <= 100) cout << "A";
  else if(80 <= score && score < 90) cout << "B";
  else if(70 <= score && score < 80) cout << "C";
  else if(60 <= score && score < 70) cout << "D";
  else cout << "F";
  return 0;
}

// putchar("FFFFFFDCBAA"[score/10]); 배열로 한 줄로 끝내는 방법 => score/10을 하여서 10개의 배열 0~10
