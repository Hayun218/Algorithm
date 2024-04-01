#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool compare(pair<int, string> a, pair<int,string> b) {
    return a.first < b.first;
}

int main() {
    // cin, cout 의 속도 높이기
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin >> N;
    
    // struct 구조체 형태로 만들어도 됨
    pair<int, string> tmp;
    vector<pair<int, string> > members;

    for(int i = 0; i < N; i++) {
        cin >> tmp.first >> tmp.second;
        members.push_back(tmp);
    }

    // 기존 순서 유지하면서 sort 하는 함수
    stable_sort(members.begin(), members.end(), compare);

    for(int i = 0; i < N; i++) {
        cout << members[i].first << ' ' << members[i].second << '\n';
    }
    return 0;
}