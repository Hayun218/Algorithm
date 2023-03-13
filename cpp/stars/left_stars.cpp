#include <iostream>
using namespace std;

int main(){
  int N;
  cout << "숫자를 입력하세요.";
  cin >> N;
  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= i; j++)
      cout << "*";
    cout << "\n";
  }
  return 0;
}
