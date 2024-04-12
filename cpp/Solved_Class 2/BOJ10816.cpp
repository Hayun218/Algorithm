/*
sort 형식으로도 가능
lower_bound, upper_bound,, 
*/

#include <iostream>

#define MAX_SIZE 500000
#define HASH_SIZE 10000000

using namespace std;
 
// minus 핸들링을 2배로 곱하는 것으로 진행,,
// 정적할당을 위해 main 외부에서 정의가 필요!
int target[MAX_SIZE + 1], cnt[2 * HASH_SIZE + 1] = {0, };

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, M, tmp;
   
    cin >> N;

    while(N--) {
        cin >> tmp;
        cnt[tmp + HASH_SIZE]++;
    }

    cin >> M;

   for(int i = 0; i < M; i++) {
        cin >> target[i];
    }
    
    for(int i = 0; i < M; i++) 
        cout << cnt[target[i] + HASH_SIZE] << ' ';

    return 0;
}