// 한번에 맞춰서 감격 ㅠㅠ 정답률이 50퍼지만..
#include <iostream>
#include <vector>
using namespace std;
vector <int> tri;

void triangle(){
  int num = 1;
  int cal = 0;
  while(1){
    if(cal > 1000) return;
    cal = (num*(num+1))/2;
    num++;
    tri.push_back(cal);
  }
}

int main(){
  int T;
  cin >> T;
  triangle();
  int size = tri.size();
  while(T--){
    int num;
    cin >> num;
    bool flag = false;

    for(int i = 0; i < size; i++)
      for(int j = 0; j < size; j++)
        for(int k = 0; k < size; k++)
          if(tri[i]+tri[j]+tri[k] == num)
            flag = true;

    if(flag)
      cout << "1" << endl;
    else cout << "0" <<endl;
  }
  return 0;
}
