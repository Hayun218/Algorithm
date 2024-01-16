#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int n[3];
  int ans = 1;

  for (int i = 0; i < 3; i++) {
    cin >> n[i];
    ans *= n[i];
  }

  string ansS = to_string(ans);
  char j[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

  for (int i = 0; i < 10; i++) {
    cout << count(ansS.begin(), ansS.end(), j[i]) << endl;
  }

  return 0;
}