#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    double avg = 0.0, num = 0.0;
    cin >> n;
    
    if (n == 0){
        cout << 0;
        return 0;
    }
    int scores[n];
    for(int i = 0; i < n; i++) cin >> scores[i];

    num = round(n * 0.15);

    sort(scores, scores+n);

    for(int i = num; i < n - num; i++)
        avg += scores[i];
    
    avg = round(avg / (n - (num*2)));

    cout << avg << '\n';

    return 0;
}