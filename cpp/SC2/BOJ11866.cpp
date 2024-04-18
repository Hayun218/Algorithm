#include<iostream>
#include<queue>
using namespace std;

int main() {
     // cin, cout 의 속도 높이기
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, k;
    queue<int> q;

    cin >> n >> k;
    
    for(int i = 1; i < n+1; i++) q.push(i);

    cout << '<';
    while(true) {
        if(q.empty()) break;
        for(int i = 1; i <= k; i++) {
            if(i != k) {
                int tmp;
                tmp = q.front();
                q.pop();
                q.push(tmp);
            } else {
                cout << q.front();
                q.pop();
                if(!q.empty()) cout << ", "; 
            }
        }
    }
        cout << '>';
        return 0;
}