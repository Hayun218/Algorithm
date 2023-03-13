#include <iostream>
using namespace std;

int factorial (int n);

int main(int argc, char* argv[]){
  int N;
  cin >> N;

  cout << factorial(N) << endl;
  return 0;
}

int factorial(int n){
  if(n == 0) return 1;
  else
    return n * (factorial(n-1));
}
