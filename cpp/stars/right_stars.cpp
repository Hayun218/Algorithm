#include <iostream>
using namespace std;

int main(){
  int N;
  cout << "숫자를 입력하세요.";
  cin >> N;

  for(int i = 1; i < N+1; i++){
    for(int j = 0; j < N-i; j++)
      cout << " ";
    for(int k = 0; k < i; k++)
      cout << "*";
    cout << "\n";
  }
  return 0;
}
