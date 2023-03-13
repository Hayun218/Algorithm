#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

int main(){
  while(1){
    bool flag = true;
    string str;
    stack<char> st;

    getline(cin, str);
    if(str.length() == 1 && str[0] == '.') break;

    for(int i = 0; i < str.length(); i++){
      if(str[i] == '(' || str[i] == '[')
        st.push(str[i]);
      else if(str[i] == ')') {
        if(!st.empty() && st.top() == '(') st.pop();
        else {
          flag = false;
          break;
        }
      }
      else if(str[i] == ']'){
        if(!st.empty() && st.top() == '[') st.pop();
        else {
          flag = false;
          break;
        }
      }
    }
    if(st.empty() && flag) cout << "yes" <<"\n";
    else cout << "no" << "\n";
  }
  return 0;
}
