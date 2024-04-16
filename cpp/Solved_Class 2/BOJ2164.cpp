#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, tmp;
    queue<int> q;

    cin >> n;

    for(int i = 0; i < n; i++) {
        q.push(i+1);
    }

    while(q.size() > 1){
		q.pop();
		q.push(q.front());
		q.pop();	
	}

    cout << q.front() << '\n';
    return 0;
}