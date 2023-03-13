#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int T, n, m, A[1001], B[1001];
  long long cnt = 0;
  vector <int> v1;
  vector <int> v2;

  scanf("%d", &T);
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", A+i);

  scanf("%d", &m);
  for(int i = 0; i < m; i++)
    scanf("%d", B+i);

  for(int i = 0; i < n; i++){
    int sum = A[i];
    v1.push_back(sum);
    for(int j = i+1; j < n; j++){
      sum += A[j];
      v1.push_back(sum);
    }
  }
  for(int i = 0; i < m; i++){
    int sum = B[i];
    v2.push_back(sum);
    for(int j  = i+1; j < m; j++){
      sum += B[j];
      v2.push_back(sum);
    }
  }

  sort(v2.begin(),v2.end());

  for(auto firArr : v1){
    int diff = T - firArr;
    auto up = upper_bound(v2.begin(), v2.end(), diff);
    auto down = lower_bound(v2.begin(), v2.end(), diff);
    cnt += (up - down);
  }
  printf("%lld\n", cnt);
  return 0;
}
