// 그리디 방법
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, ans = 0;
    cin >> n;


    while(n >= 0) {
        // 3kg로 인해 0이 되어서 if문 안으로 들어감!
        if(n % 5 == 0) {
            ans += n / 5;
            cout << ans << '\n';
            return 0;
        }
        n -= 3;
        ans++;
    }
    cout << "-1\n";
    return 0;
}