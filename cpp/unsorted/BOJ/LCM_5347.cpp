// LCM_5347
#include <iostream>
using namespace std;

long long gcd(long long a, long long b){
  return a%b == 0 ? b : gcd(b, a%b);
}

long long lcm(long long a, long long b){
  return  (a*b)/gcd(a,b);
}

int main(){
  long long n, a, b;
  cin >> n;
  while(n--){
    cin >> a >> b;
    cout << lcm(a, b) << endl;
  }
  return 0;
}
