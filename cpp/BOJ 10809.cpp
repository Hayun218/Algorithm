#include <iostream>
#include <string>

using namespace std;

int main() {
    string S;
    char n;
    int i;   
     
    cin >> S; 

    for(n = 'a'; n <= 'z'; n++) {
        for(i = 0; i < S.size(); i++) {
            if(char(S[i]) == n) break;
        }
        if(i == S.size()) i = -1;
        cout << i << " ";
    }
    return 0;
}