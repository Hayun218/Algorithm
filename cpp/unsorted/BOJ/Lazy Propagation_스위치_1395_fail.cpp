// Lazy Propagation_스위치_1395_fail

#include <cstdio>
#include <algorithm>
using namespace std;
const int max_N = 100001;

int N, M, O, S, T;
bool lazy[4*max_N];
int seg[4*max_N];

void propagate(int node, int s, int e){
  if(lazy[node]){
    seg[node] = (e - s + 1) - seg[node]; // 반대로 뒤집히니까
    if(s != e){
      lazy[node * 2] ^= 1; // XOR 연산자
      lazy[node * 2 +1] ^= 1;
    }
    lazy[node] = false;
  }
  else return;
}

void update(int l, int r, int node, int s, int e){
  propagate(node, s, e);
  if(r < s || l > e) return;
  if(l >= s && e <= r){
    if(s!=e) {
      lazy[node*2] ^= 1;
      lazy[node*2+1] ^= 1;
    }
  return;
  }
  int mid = (s+e) / 2;
  update(l, r, node*2, s, mid);
  update(l, r, node*2+1, mid, e);
  seg[node] = seg[node*2] + seg[node*2+1];
}

int count(int l, int r, int node, int s, int e){
  propagate(node, s, e);
  if (r < s || l > e)  return 0;
  if (l >= s && e <= r) return seg[node];
  int mid = (s+e)/2;
  return count(l, r, node * 2, s, mid) + count(l, r, node * 2 + 1, mid + 1, e);
}

int main(){
  scanf("%d %d", &N, &M);
  while(M--){
    scanf("%d %d %d", &O, &S, &T);
    if(O) printf("%d\n", count(S, T, 1, 1, N));
    else update(S, T, 1, 1, N);
  }
  return 0;
}
