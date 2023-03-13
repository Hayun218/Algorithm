#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
  string num, rev;
  int T = 0; cin >> T;

  while(T--){
    cin >> num;
    rev = num;
    reverse(rev.begin(), rev.end());


    //int sum = stoi(rev) + stoi(num); // -??
    int sum = atoi(rev.c_str()) + atoi(num.c_str());
    string ans = to_string(sum);

    rev.clear();
    rev = ans;

    reverse(rev.begin(), rev.end());

    if(rev == ans)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
