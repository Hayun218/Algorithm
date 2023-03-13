// Fenwick_전구_2550

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = -987654321;

int main(){
  int n;
  scanf("%d", &n);

  vector<int> idx(n+1);
  vector<int> val(n+1);
  vector<int> arr(n+1);

  for(int i = 0; i < n; i++){
    int num;
    scanf("%d", &num);

    idx[num] = i; // 해당 숫자의 인덱스 넣기
    val[i] = num;
  }

  for(int i = 0; i < n; i++){
    int num;
    scanf("%d", &num);

    arr[i] = num;
  }

  vector<int> lis(n);
  vector<pair<int, int> > trace;

  int plis = 0;

  lis[0] = arr[0];
  trace.push_back({0, arr[0]});

  for(int i = 1; i < n; i++){
    auto it = lower_bound(lis.begin(), lis.end(), i);
    lis[it] = arr[i];
    trace.push_back({it, arr[i]});
  }

  for(int i = 0; i < lis.size(); i++){
    if(lis[i] != )
  }






}
