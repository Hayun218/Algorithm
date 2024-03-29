#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
  int N;
  string command;
  stack<int> st;

  cin >> N;
  cin.ignore();

  while(N--){

    string str1, str2;

    int num;
    // 공백포함 문자열 입력받기
    getline(cin, command);

    if(command.find(" ") != string::npos){

      str1 = command.substr(0, command.find(" "));
      str2 = command.substr(command.find(" ") + 1, command.length());

      num = atoi(str2.c_str());
    }else{
      str1 = command;
    }

    if(str1.compare("push") == 0){
      st.push(num);
    }else if(str1.compare("pop") == 0){
      if(!st.empty()){
        cout << st.top() << endl;
        st.pop();
      } else{
        cout << "-1\n";
      }
    } else if(str1.compare("size")==0){
      cout << st.size() << endl;
    } else if(str1.compare("empty") == 0){
      if(st.empty()){
        cout << 1 << endl;
      }else{
        cout << 0 << endl;
      }
    } else if(str1.compare("top") == 0){
      if(st.empty()){
        cout << -1 << endl;
      }else{
        cout << st.top() << endl;
      }
    }
  }

  return 0;
}
