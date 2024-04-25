#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, sum = 0;
    stack<int> st;

    cin >> n;

    while(n--) {
        int tmp;
        cin >> tmp;
        if(tmp == 0) st.pop();
        else {
            st.push(tmp);
        }
    }

    while(!st.empty()) {
        sum += st.top();
        st.pop();
    }
    cout << sum << '\n';
    return 0;
}