// 2019.12.18 내일 다시해보기!
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
typedef long long ll;
using namespace std;
vector <pair<string, pair <int, int>> > input;
int T;

bool solution(vector <int> &v){
  bool flag = true;
  for(int i = 0; i < T; i++){
    int s = 0, b = 0;
    for(int j = 0; j < 3; j++)
      for(int k = 0; k < 3; k++){
        if(v[j] == (input[i].first[k] - '0')){
          if(j == k) s++;
          else b++;
          break;
        }
      }
      if(s != input[i].second.first || b != input[i].second.second){
        flag = false;
        break;
      }
  }
  return flag;
}

int main(){
  int strike, ball;
  string guess;
  cin >> T;

  for(int i = 0; i < T; i++){
    cin >> guess >> strike >> ball;
    input.push_back({guess, make_pair(strike, ball)});
  }

  ll result = 0;
  for(int i = 1; i < 10; i++){
    vector<int> pos;
    pos.push_back(i);
    for(int j = i+1; j < 10; j++){
      pos.push_back(j);
      for(int k = j+1; k < 10; k++){
        pos.push_back(k);
        do{
          if(solution(pos))
            result++;
        } while(next_permutation(pos.begin(), pos.end()));
        pos.pop_back();
      }
      pos.pop_back();
    }
    pos.pop_back();
  }
  cout << result << endl;
  return 0;
}
