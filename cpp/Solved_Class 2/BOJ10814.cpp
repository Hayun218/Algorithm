#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string map[100000][2];

    int N, i;
    scanf("%d", &N);

    for(i = 0; i < N; i++) scanf("%s %s", &map[i][0], &map[i][1]);
    
    sort(&map[0][0], &map[N][0]);

    for(i = 0; i < N; i++) 
        printf("%s %s", map[i][0], map[i][1]);


    return 0;
}