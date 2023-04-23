#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(){
  int N;
  string command;
  queue<int> qu;

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
      qu.push(num);
    }else if(str1.compare("pop") == 0){
      if(!qu.empty()){
        cout << qu.front() << endl;
        qu.pop();
      } else{
        cout << "-1\n";
      }
    } else if(str1.compare("size")==0){
      cout << qu.size() << endl;
    } else if(str1.compare("empty") == 0){
      if(qu.empty()){
        cout << 1 << endl;
      }else{
        cout << 0 << endl;
      }
    } else if(str1.compare("front") == 0){
      if(qu.empty()){
        cout << -1 << endl;
      }else{
        cout << qu.front() << endl;
      }
    }else if(str1.compare("back") == 0){
      if(qu.empty()){
        cout << -1 << endl;
      }else{
        cout << qu.back() << endl;
      }
    }
  }

  return 0;
}
