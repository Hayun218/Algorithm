#include<iostream>
#define MAX 10001
using namespace std;

int num[MAX], n, tmp;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> tmp;
        num[tmp]++;
    }
    
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < num[i]; j++) 
            cout << i << '\n';
    }
    
    return 0;
}