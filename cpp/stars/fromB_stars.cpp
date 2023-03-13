#include <iostream>
using namespace std;

int main(){
  int N;
  cout << "숫자를 입력하세요. ";
  cin >> N;

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N - i; j++)
      cout << "*";
    cout << "\n";
  }
  return 0;
}
