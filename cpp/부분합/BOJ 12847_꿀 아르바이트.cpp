#include <iostream>
#include <algorithm>
#define n_MAX 100001
using namespace std;

int T[n_MAX];

int main(){
  int n, m;
  long long ans = 0, temp = 0;
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    cin >> T[i];
    if(i < m) temp += T[i];
  }
  ans = temp;
  for(int i = m; i < n; i++){
    temp += T[i] - T[i-m]; // core
    ans = max(temp, ans);
  }

  cout << ans << endl;
  return 0;
}
