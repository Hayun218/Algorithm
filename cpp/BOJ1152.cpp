#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    getline(cin, s);

    int cnt = 1;

    for (int i = 0; s[i]; i++) {
        if (char(s[i] == ' ' && s.size() == 1)) cnt = 0;
        else if (char(s[i]) == ' ' && i != 0 && i != s.size()-1) cnt++; 

    }
    printf("%d\n", cnt);

    return 0;
}