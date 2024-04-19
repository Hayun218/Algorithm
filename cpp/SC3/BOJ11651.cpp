#include<iostream>
#include<algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
   if(a.second == b.second) {
        return a.first < b.first;
    } else return a.second < b.second;
}

int main() {
    int n;
    pair<int, int> c[100000];

    cin >> n;

    for(int i = 0; i < n; i++) 
        cin >> c[i].first >> c[i].second;
    
    sort(c, c+n, compare);

    for(int i = 0; i < n; i++) 
        cout << c[i].first << ' ' << c[i].second << '\n';

    return 0;
}