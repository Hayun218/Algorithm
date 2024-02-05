#include <iostream>
#include <algorithm>
using namespace std;

bool compare(string a, string b) {
    if(a.length() == b.length()) return a < b;
    else return (a.length() < b.length()); 
}

int main() {
    int N, i;
    cin >> N;

    string words[N];

    for(i = 0; i < N; i++)  cin >> words[i];
    
    sort(words, words+N, compare);

     for(i = 0; i < N; i++)  {
        if(i != 0 && words[i-1] == words[i]) continue;
        cout << words[i] << endl;
     }
    
    return 0;
}