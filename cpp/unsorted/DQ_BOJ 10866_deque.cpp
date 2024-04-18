#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main(){
  int N;
  string command;
  deque<int> dq;

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
    
    // push_front
    if(str1.compare("push_front") == 0){
      dq.push_front(num);
    }

    else if(str1.compare("push_back") == 0){
      dq.push_back(num);
    }
    
    
    else if(str1.compare("pop_front") == 0){
      if(!dq.empty()){
        cout << dq.front() << endl;
        dq.pop_front();
      } else{
        cout << "-1\n";
      }
    } 
    else if(str1.compare("pop_back") == 0){
      if(!dq.empty()){
        cout << dq.back() << endl;
        dq.pop_back();
      } else{
        cout << "-1\n";
      }
    } 
    
    else if(str1.compare("size")==0){
      cout << dq.size() << endl;
    } 
    
    else if(str1.compare("empty") == 0){
      if(dq.empty()){
        cout << 1 << endl;
      }else{
        cout << 0 << endl;
      }
    } 
    
    else if(str1.compare("front") == 0){
      if(dq.empty()){
        cout << -1 << endl;
      }else{
        cout << dq.front() << endl;
      }
    }
    
    
    else if(str1.compare("back") == 0){
      if(dq.empty()){
        cout << -1 << endl;
      }else{
        cout << dq.back() << endl;
      }
    }
  }

  return 0;
}
