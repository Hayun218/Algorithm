#include <iostream>
#include <cmath>
using namespace std;

void calculate(int a, int b, int c){
  cout<<fixed;
  cout.precision(3);
  int result;
  if(c == -1){
    result = pow(a, 2.0)+pow(b,2.0);
    cout << "c = ";
  }
  else if(a == -1){
    result = pow(c,2)-pow(b,2);
    if(result <= 0){
      cout << "Impossible."<<endl;
      return;
    }
    cout << "a = ";
  }
  else if(b == -1){
    result = pow(c,2)-pow(a,2);
    if(result <= 0){
      cout << "Impossible."<<endl;
      return;
    }
    cout << "b = ";
  }
  cout << sqrt(result) <<endl;
  return;
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int idx = 1;
  while(1){
    int a, b, c;
    cin >> a >> b >> c;
    if(a == 0 && b == 0 && c == 0) break;
    cout << endl << "Triangle #" << idx << endl;
    calculate(a,b,c);
    idx++;
  }
  return 0;
}
