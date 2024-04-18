#include <iostream>
#include <algorithm>
using namespace std;

// bool compare(pair<int, int> a, pair<int, int> b) {
//     if (a.first == b.first) {
//         return a.second < b.second;
//     } else {
//         return a.first < b.first;
//     }
// }

int main() {
     // cin, cout 의 속도 높이기
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    pair<int, int> pos[100000];
    // vector<pair<int, int> > pos;
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        cin >> pos[i].first >> pos[i].second;
    }

    sort(pos, pos+N); //, compare);
     for(int i = 0; i < N; i++) {
        cout << pos[i].first << ' ' << pos[i].second << '\n';
    }

    return 0;
}