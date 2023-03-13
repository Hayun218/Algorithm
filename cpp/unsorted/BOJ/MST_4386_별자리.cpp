// 4386_별자리만들기

#include <cstdio>
#include <algorithm>
#include <cmath>
#define SQ(x) ((x)*(x))
using namespace std;

const int max_N = 101;
const int max_s = (101*100)/2;

double parent[max_N];

pair<double, pair<int, int > > v[max_s];
pair<double, double> pos[max_N];

double dis(pair<double, double> &a, pair<double, double> &b){
  return sqrt((double(SQ(b.first - a.first))) + (double(SQ(b.second - a.second))));
}

double find(int x){
  if(parent[x] == x) return x;
  return parent[x] = find(parent[x]);
}

/*

bool merge(int x, int y){
  x = find(x);
  y = find(y);
    if(x == y) return false;
    parent[y] = x;
    return true;
}

int main(){
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%lf %lf", &pos[i].first, &pos[i].second);

  int Size = (n*(n-1))/2;

  for(int i = 0, e = 0; i < n; i++){
    for(int j = i+1; j < n; j++, e++){
      v[e].first = dis(pos[i], pos[j]);
      v[e].second.first = i;
      v[e].second.second = j;
    }
  }
  sort(v, v+Size);
  int cnt = 0;
    double ans = 0;
  for(int i = 0; i < Size; i++){
    int a = v[i].second.first;
    int b = v[i].second.second;
    if(!merge(a, b)){
      cnt++;
      ans += v[i].first;
    }
    if(cnt == n-1) break;
  }
  printf("%.2f\n", ans);

  return 0;
}
