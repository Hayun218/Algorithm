// 세 수
#include <iostream>
using namespace std;

int main(){
  int max = 0, ans = 0;
  int num[3];
  for(int i = 0; i < 3; i++){
    cin >> num[i];
    if(num[i] > max)
      max = num[i];
    else if(ans <= num[i] && max > num[i])
      ans = num[i];
  }
  cout << ans;
  return 0;
}
