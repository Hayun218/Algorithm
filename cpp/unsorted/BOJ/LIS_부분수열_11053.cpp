#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = -987654321;

int main(){
  int N;
  scanf("%d", &N);

  int A[N+1];
  vector <int> arr(N+1);

  for(int i = 0; i < N; i++)
    scanf("%d", A+i);

  arr.push_back(INF);
  int ans = 0;

  for(int i = 0; i < N; i++){
    if(A[i] > arr.back()){
      arr.push_back(A[i]);
      ans++;
    }
    else{
      auto it = lower_bound(arr.begin(), arr.end(), A[i]);
      *it = A[i];
    }
  }
  printf("%d", ans);
  return 0;
}
/*
// 빠르고 간단한 맞은 풀이
#include <cstdio>
int main(){
	int n, a[1010], d[1010], m=0, i=0, j;
	for(scanf("%d", &n); i<n; scanf("%d", &a[i++]));
	for (i=0; i<n; i++){
		for (j=0, d[i]=1; j<i; j++)
			if (a[j] < a[i] && d[i] < d[j]+1) d[i] = d[j] + 1;
		if (m<d[i]) m=d[i];
	}
	printf("%d\n", m);
}*/
