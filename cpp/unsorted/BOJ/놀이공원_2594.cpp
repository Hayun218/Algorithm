#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector < pair<int, int> > timeR;
int duration[51];

int main(){
  cin >> N;
  for(int i = 0; i < N; i++){
    int start, end;
    cin >> start >> end;
    start = (start/100)*60 + (start%100)-10;
    end = (end/100)*60 + (end%100)+10;
    timeR.push_back(make_pair(start, end));
  }

  sort(timeR.begin(), timeR.end());
  duration[0] = timeR[0].first - (1000/100)*60;
  duration[N] = (2200/100)*60 - timeR[N-1].second;

  for(int i = 0; i < N; i++)
    duration[i] = (timeR[i+1].first) - (timeR[i].second);

  int maxi = 0;
  for(int i = 0; i < N; i++)
    if(maxi < duration[i])
      maxi = duration[i];
  printf("%d\n", maxi);
  return 0;
}
