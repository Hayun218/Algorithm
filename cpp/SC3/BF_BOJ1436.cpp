#include<iostream>
#include<string>
using namespace std;

int findTitle(int cnt) {
    int n = 666;
    string title;
    int series = 0;

     while(1) {
        title = to_string(n);
        for(int i = 0; i < title.size() - 2; i++) {
            if(title[i] == '6' && title[i+1] == '6' && title[i+2] == '6') {
                series++;
                if(series == cnt) return n;
                break;
            } 
        }
        n++;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int cnt;

    cin >> cnt;

    cout << findTitle(cnt);
}