#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	int num;
  string sen;
  stack<char> st;
  
	cin >> num;
  cin.ignore();

	while (num--) {
    getline(cin, sen);

    // last word
    sen += ' ';

    for(int i = 0; i < sen.size(); i++){
      if(sen[i] == ' '){
        while(!st.empty()){
          cout << st.top();
          st.pop();
        }
        cout << " ";
      }
      else st.push(sen[i]);
    }
	}

	return 0;
}
