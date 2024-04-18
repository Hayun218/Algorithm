#include <iostream>
using namespace std;

char map[50][50];

// color => 첫번쩨 시작 색상
int countNum(int x, int y, char color) {
    int cnt = 0;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            // 짝수 인덱스는 첫번째 색상과 동일해야 옳기에 다르면 ++
            if((i + j) % 2 == 0 && map[x+i][y+j] != color) cnt++;
            else if((i + j) % 2 != 0 && map[x+i][y+j] == color) cnt++;
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int m, n;
    int ans = 8*8;

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    for(int i = 0; i + 8 <= n; i++) {
        for(int j = 0; j + 8 <= m; j++) {
            int tmp;
            tmp = min(countNum(i, j, 'W'), countNum(i, j, 'B'));
            if(ans > tmp) ans = tmp;
        }
    }
    cout << ans << '\n';

    return 0;
}