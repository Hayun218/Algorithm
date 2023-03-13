#include <cstdio>
using namespace std;
 
int main(){
    int N, M, height[1000000];
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
        scanf("%d", height+i);
    
    int low = 0, hi = 1000000000;
    // 이분 탐색 시작
    while(low + 1 < hi){
        int check = (low + hi) / 2;

        long long sum = 0;
        for(int i = 0; i < N; i++)
            if(height[i] > check) sum += height[i] - check;

        if(sum >= M) low = check;
        
        else hi = check;
    }
    printf("%d\n", low);
}