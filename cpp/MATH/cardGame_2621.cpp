#include <cstdio>
#include <algorithm>
using namespace std;

int numbers[10] = {0, };
int colors[4]; // B, R, Y, G

// 제일 큰 숫자 반환
int maxNumber(){
  int maxN = 1;
  for(int i = 2; i < 10; i++)
    if(numbers[i] >= 1)
      maxN = max(maxN, i);
  return maxN;
}

int main(){
  for(int i = 0; i < 5; i++){
    char color; int num;
    scanf(" %c %d", &color, &num);
    if(color == 'B')
      colors[0]++;
    if(color == 'R')
      colors[1]++;
    if(color == 'Y')
      colors[2]++;
    if(color == 'G')
      colors[3]++;
    numbers[num]++;
  }
  // 모든 색상 동일 여부
  bool allColor = false;
  // 숫자 연속적
  bool inOrder = false;

// 색상 동일 여부 판단
  for(int i = 0; i < 5; i++){
    if(colors[i] == 5){
      allColor = true;
      break;
    }
  }
  // 숫자의 연속성 판단
  int cnt = 0;
  for(int i = 0; i < 10; i++){
    if(cnt == 5){
      inOrder = true;
      break;
    }
    if(numbers[i] == 1)
      cnt++;
    else
      cnt = 0;
  }

  // 숫자 동일 판단
  int fourI = 0, threeI = 0, two1I = 0, two2I = 0;

  for(int i = 1; i < 10; i++){
    if(numbers[i] == 4)
      fourI = i;

    if(numbers[i] == 3)
      threeI = i;

    if(two1I && numbers[i] == 2){
      two2I = i;
      continue;
    }

    if(numbers[i] == 2)
      two1I = i;
  }

  int ans = 0;
  int big = maxNumber();
  // 규칙 1
  if(allColor && inOrder){
    ans = big + 800;
  } else if (fourI){
    ans = fourI + 800;
  } else if(threeI && two1I){
    ans = threeI*10+two1I+700;
  } else if(allColor){
    ans = big + 600;
  } else if(inOrder){
    ans = big + 500;
  } else if(threeI){
    ans = threeI + 400;
  } else if(two1I && two2I){
    if(two1I > two2I)
      ans = two1I*10 + two2I + 300;
    ans = two2I*10 + two1I + 300;
  } else if(two1I){
    ans = two1I + 200;
  } else {
    ans = big +100;
  }

  printf("%d\n", ans);
  return 0;
}
