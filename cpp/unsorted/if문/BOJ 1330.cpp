// 두 수 비교하기_1330

#include <iostream>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int A, B;
  cin >> A >> B;
  if(A > B)
    cout << ">";
  else if(A == B)
    cout << "==";
  else
    cout << "<";
  return 0;
}
