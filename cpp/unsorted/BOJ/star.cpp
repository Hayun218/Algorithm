#include <cstdio>
const int Max_N = 101;

int main()
{
    int N;
    scanf("%d", &N);
    
    for(int j = 0; j < N; j++){
        for(int i = 0; i <= j; i++)
            printf("*");
    printf("\n");
    }
    return 0;
}