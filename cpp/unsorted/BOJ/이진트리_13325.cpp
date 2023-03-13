// 이진트리_13325

#include <cstdio>
#include <algorithm>
const int max_ = 1 << 21;
using namespace std;

int main(){
  int n, e;
  scanf("%d", &n);
  int size = 1 << (n+1);
  int tree[max_] = {0}, path[max_] = {0}, sum[max_] = {0}, left, right;
  for(int i = 2; i < size; i++){
    scanf("%d", &e);
    tree[i] = e;
  }
  for(int i = 1 << n; --i > 0; ){
    left = i << 1, right = left +1;
    path[i] = max(tree[left] + path[left], tree[right]+path[right]);
    sum[i] = sum[left]+sum[right] + (path[i] - tree[left]) + (path[i] - tree[right]);
  }

  printf("%d\n", sum[1]);
  return 0;
}
