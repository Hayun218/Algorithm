//풀어보기
#include <iostream>
#include <algorithm>
using namespace std;

int L, C;
int A[15], P[16];
bool isVowel[26];


int main()
{
    scanf("%d %d", &L, &C);
    for(int i = 0; i < C; i++)
        scanf("%d", A+i);
    sort(A, A+C);
    
}