#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        string st;
        cin >> st;

        stack<char> s;

        for (int i = 0; i < st.length(); i++) {
            if (st[i] == '(')
                s.push(st[i]);
            else if (st[i] == ')') {
                if (!s.empty()) s.pop();
                else {
                    cout << "NO\n";
                    break;
                }
            }
            if (i == st.length() - 1) {
                if (s.empty()) cout << "YES\n";
                else cout << "NO\n";
            }
        }
    }
    return 0;
}