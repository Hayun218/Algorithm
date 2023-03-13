  #include <cstdio>
  #include <algorithm>
  #include <vector>
  using namespace std;

  vector <int> nan;
  int sum;

  void ans(){
    for(int i = 0; i < 8; i++){
      for(int j = 1; j < 9; j++){
        if(sum - nan[i] - nan[j] == 100){
          for(int k = 0; k < 9; k++){
            if(k != i && k != j)
              printf("%d\n", nan[k]);
          }
          return;
        }
      }
    }
  }

  int main(){
    sum = 0;
    for(int i = 0; i < 9; i++){
      int h;
      scanf("%d", &h);
      nan.push_back(h);
      sum += h;
    }
    sort(nan.begin(), nan.end());
    ans();
    return 0;
  }
