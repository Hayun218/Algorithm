#include<iostream>
using namespace std;

int fibonacci(int a) {
    if(a < 2) return 1;
    else return a * fibonacci(a-1);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, fi, cnt = 0;
    cin >> n;

    fi = fibonacci(n);

    while(fi % 10 == 0) {
        fi = fi / 10;
        cnt++;
    }

    cout << cnt << '\n';

    return 0;
}