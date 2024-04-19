#include<iostream>
#include<utility>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    int rank = 1;
    pair<int,int> p[50];

    cin >> n;

    for(int i = 0; i < n; i++) 
        cin >> p[i].first >> p[i].second;

    for(int i = 0; i < n; i++) {
       for(int j = 0; j < n; j++) {
        if(i==j) continue;
        if(p[i].first > p[j].first && p[i].second > p[j].second) continue;
        else if(p[i].first < p[j].first && p[i].second < p[j].second) rank++;
        else continue;
       }
       cout << rank << ' ';
       rank = 1;
    }
       
    return 0;
}