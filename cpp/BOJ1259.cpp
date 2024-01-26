#include <iostream>
#include <cstring>
using namespace std;

int main() {

    while(true) {
        string N;
        int i;
        cin >> N;

        if(char(N[0]) == '0') return 0;

        for(i = 0; i < N.size()/2; i++) {
            if (N[i] == N[N.size() - (i+1)]) continue;
            else break;
        }
        
        if(i == N.size()/2) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}