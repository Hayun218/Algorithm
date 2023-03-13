#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int d, n, m, dn[50005];
  cin >> d >> n >> m;

  for(int i = 0; i < n; i++)
    cin >> dn[i];
  dn[n] = d; dn[n+1] = 0;

  sort(dn, dn+n+2);

  int left = 0, right = d, ans = 0;
  while(left <= right){
    int mid = (left+right)/2;
    int cnt = 0, pre = 0;

    for(int i = 1; i < n+2; i++){
      if(dn[i] - dn[pre] < mid) cnt++;
      else pre = i;
    }

    if(cnt > m)
      right = mid - 1;
    else {
      left = mid + 1;
      ans = mid;
    }
  }
  cout << ans << "\n";
  return 0;
}
